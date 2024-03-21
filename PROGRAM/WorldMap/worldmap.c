#define MAPSPEED	1.0	// ccc mapships - Petros: reset to 1.0 to prevent trouble, was 0.6
//#define MAP_VOYAGELENGTH	8.0 // TIH moved to BS.h	// ccc maptweak, lets voyages take longer, original 4.0

#include "worldmap\worldmap_globals.c"
#include "worldmap\worldmap_events.c"
#include "worldmap\worldmap_reload.c"
#include "worldmap\worldmap_encgen.c"
#include "worldmap\DailyCrewUpdate.c" // NK

//=========================================================================================

extern void wdmInitWorldMap();

#event_handler("WorldMap_EncounterCreate", "wdmEvent_EncounterCreate");
#event_handler("WorldMap_inside_islandzone", "wdmEvent_InsideIsland");
#event_handler("WorldMap_outside_islandzone", "wdmEvent_OutsideIsland");
#event_handler("WorldMap_PlayerInStorm", "wdmEvent_PlayerInStorm");
#event_handler("WorldMap_ShipEncounter", "wdmEvent_ShipEncounter");
#event_handler("WorldMap_EventWindowChangeSelectoin", "wdmEvent_EventWindowChangeSelectoin");
#event_handler("WorldMap_EventWindowSelect", "wdmEvent_EventWindowSelect");
#event_handler("WorldMap_WaitMenuChangeSelectoin", "wdmEvent_WaitMenuChangeSelectoin");
#event_handler("WorldMap_WaitMenuSelect", "wdmEvent_WaitMenuSelect");
#event_handler("WorldMap_DeleteShipEncounter", "wdmEvent_DeleteShipEncounter");
#event_handler("WorldMap_UpdateDate", "wdmEvent_UpdateDate");
#event_handler("ExitFromWorldMap", "wdmReloadToSea");
#event_handler("EventLoadLocation", "wdmOpenLocation");

#event_handler("EventTimeUpdate", "wdmTimeUpdate");

//=========================================================================================
// Programm interface
//=========================================================================================
bool wdmNoClearEncountersTable = false;


void wdmTimeUpdate()
{
	PostEvent("EventTimeUpdate", 5000);
}

void wdmCreateMap(float dx, float dz, float ay)
{
    trace("Player sea position:");
    trace("x = " + dx);
    trace("z = " + dz);
    trace("Old worldmap position:");
    trace("x = " + worldMap.playerShipX);
    trace("z = " + worldMap.playerShipZ);
	float fadeInTime = 0.5; // KK
	//float zeroX = MakeFloat(worldMap.zeroX);
	//float zeroZ = MakeFloat(worldMap.zeroZ);
    int scale = WDM_MAP_TO_SEA_SCALE;
	wdmDisableTornadoGen = true;

   // worldMap.playerShipX = (dx/scale) + zeroX;
	//worldMap.playerShipZ = (dz/scale) + zeroZ;
	worldMap.playerShipAY = ay;
	ClearAllLogStrings();
	wdmDisableRelease = true;
	//Create world map engine object
	ReloadProgressStart();
	wdmRemoveOldEncounters();
//	Trace("Save check ---------------================--------------")
//	DumpAttributes(&worldMap);
//	Trace("Save check ###########----================--------------")
	worldMap.playerInStorm = 0;
	worldMap.resizeRatio = HUD_SCALING;
    wdmReset();
    worldMap.date.hourPerSec = MAP_VOYAGELENGTH;	// ccc maptweak original 4.0
	worldMap.date.monthnames.m01 = XI_ConvertString("target_month_1");
    worldMap.date.monthnames.m02 = XI_ConvertString("target_month_2");
    worldMap.date.monthnames.m03 = XI_ConvertString("target_month_3");
    worldMap.date.monthnames.m04 = XI_ConvertString("target_month_4");
    worldMap.date.monthnames.m05 = XI_ConvertString("target_month_5");
    worldMap.date.monthnames.m06 = XI_ConvertString("target_month_6");
    worldMap.date.monthnames.m07 = XI_ConvertString("target_month_7");
    worldMap.date.monthnames.m08 = XI_ConvertString("target_month_8");
    worldMap.date.monthnames.m09 = XI_ConvertString("target_month_9");
    worldMap.date.monthnames.m10 = XI_ConvertString("target_month_10");
    worldMap.date.monthnames.m11 = XI_ConvertString("target_month_11");
    worldMap.date.monthnames.m12 = XI_ConvertString("target_month_12");
    worldMap.date.font = "normal";
    worldMap.outputRum = true;
    //#20210827-01
    // worldMap.legacyArea = true;					// enables old legacy circled areas
    // worldmap.wdmCameraAYDefault = PI;			//Rotation angle of the camera
	DeleteAttribute(&worldmap, "legacyArea");
	// worldmap.debug = "true";			// display yellow circles around islands to edit areas
// KK -->
	//Boyer change
	if (bNewInterface)
		worldMap.BaseIslands = "islands\islands";
//		CreateEntity(&worldMap, "wrldmap2");
//	else
		CreateEntity(&worldMap,"worldmap");
// <-- KK
	worldMap.isLoaded = "true";
	//Set player ship position
	worldMap.playerShipDispX = dx / WDM_MAP_TO_SEA_SCALE;
	worldMap.playerShipDispZ = dz / WDM_MAP_TO_SEA_SCALE;
	//Update parameters
	worldMap.update = "";
	//Reset encounters data
	wdmReset();
	worldMap.playerShipUpdateDisp = "";
	if (wdmNoClearEncountersTable == false) ReleaseMapEncounters();
	wdmNoClearEncountersTable = false;
	//Fade in
// KK -->
	if (!IsEntity(&wdm_fader)) {
		CreateEntity(&wdm_fader, "fader");
		if (IsEntity(&wdm_fader)) {
			SendMessage(&wdm_fader, "lfl", FADER_IN, fadeInTime, true);
			SendMessage(&wdm_fader, "ls", FADER_PICTURE0, FindReloadPicture("sea.tga")); // KK
		} else {
			trace("Fader not created!!!");
		}
	}
// <-- KK
	SetSchemeForMap();
	Event("EventWorldMapInit"); // KK
	ReloadProgressEnd();

	// ccc maptweak
	//worldMap.date.hourPerSec = MAP_VOYAGELENGTH;	// ccc maptweak original 4.0
	SetTimeScale(MAPSPEED);			// slow motion
	//SetWeatherScheme("seashore_weather");
	// ccc maptweak end
	InitWmInterface();
}

void wdmCreateWorldMap()
{
	float dshipX = MakeFloat(worldMap.playerShipDispX)*WDM_MAP_TO_SEA_SCALE;
	float dshipZ = MakeFloat(worldMap.playerShipDispZ)*WDM_MAP_TO_SEA_SCALE;
	float shipAY = MakeFloat(worldMap.playerShipAY);
	wdmCreateMap(dshipX, dshipZ, shipAY);
}

void wdmLoadSavedMap()
{
	float dshipX = MakeFloat(worldMap.playerShipDispX)*WDM_MAP_TO_SEA_SCALE;
	float dshipZ = MakeFloat(worldMap.playerShipDispZ)*WDM_MAP_TO_SEA_SCALE;
	float shipAY = MakeFloat(worldMap.playerShipAY);
	wdmNoClearEncountersTable = true;
	wdmCreateMap(dshipX, dshipZ, shipAY);
}

void wdmRemoveOldEncounters()
{
	//???????????????????????????? ???????????????????????????????????? ????????????????????????????????????????
	wdmMarkDeleteEncounters();
	//????????????????????????????????? ???????????????? ????????????????????????????????
	aref encs;
	makearef(encs, worldMap.encounters);
	int num = GetAttributesNum(encs);
	object forDelete;
	string attr, encID;
	int count = 0;

	for(int i = 0; i < num; i++)
	{
		aref enc = GetAttributeN(encs, i);
		if(CheckAttribute(enc, "needDelete") != 0)
		{
			attr = "del" + count;
			forDelete.(attr) = GetAttributeName(enc);
			count = count + 1;
		}
	}
	for(i = 0; i < count; i++)
	{
		attr = "del" + i;
		encID = "encounters." + forDelete.(attr);
		DeleteAttribute(&worldMap, encID);
	}
}

float wdmGetDays(int year, int month, int day, int hour)
{
	//????????????????????????????? ???????????? ???????? ????????????????????
	if(year < 0) year = 0;
	if(year > 3000) year = 3000;
	year = year*365;
	//????????????????????????????? ???????????????????? ????????????
	for(int i = 1; i < month; i++)
	{
		day = day + GetMonthDays(i, year);
	}
	//????????????????????????????? ???????????????????????? ????????????
	float days = year + day + (hour/24.0);
	return days;
}

void wdmMarkDeleteEncounters()
{
	//???????????????????????????????? ????????????????
	int year = sti(worldMap.date.year);
	int month = sti(worldMap.date.month);
	int day = sti(worldMap.date.day);
	int hour = sti(worldMap.date.hour);
	float days = wdmGetDays(year, month, day, hour);
	int encYear, encMonth, encDay, encHour;
	//???????????????????????????????????????? ???????????? ????????????????????????????????????????, ???????????????????????????? ???????? ????????????????????????????????
	aref encs;
	makearef(encs, worldMap.encounters);
	int num = GetAttributesNum(encs);
	for(int i = 0; i < num; i++)
	{
		aref enc = GetAttributeN(encs, i);
		if(CheckAttribute(enc, "Quest") != 0)

		{
			continue;
		}
		bool deleteMe = false;
		if(CheckAttribute(enc, "year") != 0)
		{
			encYear = sti(enc.year);
		}else{
			deleteMe = true;
		}
		if(CheckAttribute(enc, "month") != 0)
		{
			encMonth = sti(enc.month);
		}else{
			deleteMe = true;
		}
		if(CheckAttribute(enc, "day") != 0)
		{
			encDay = sti(enc.day);
		}else{
			deleteMe = true;
		}
		if(CheckAttribute(enc, "hour") != 0)
		{
			encHour = sti(enc.hour);
		}else{
			deleteMe = true;
		}
		if(deleteMe != true)
		{
			float deltaDays = wdmGetDays(encYear, encMonth, encDay, encHour) - days;
			if(deltaDays < 0)
			{
				deltaDays = -deltaDays;
			}
			if(deltaDays > 1.0)
			{
				deleteMe = true;
			}
		}
		if(deleteMe != false)
		{
			enc.needDelete = "Time delete";
		}
	}
}

void wdmOpenLocation()
{
	//?????????????????? ???????????????? ??????????????
	if(!TestRef(loadedLocation)) return;
	if(!IsEntity(loadedLocation)) return;
	if(!CheckAttribute(loadedLocation, "worldmap")) return;
	//?????????????????? ?????? ??????????????
	aref islands;
	makearef(islands, worldMap.islands);
	int num = GetAttributesNum(islands);
	for(int i = 0; i < num; i++)
	{
		aref isl = GetAttributeN(islands, i);
		if(!CheckAttribute(isl, "locations")) continue;
		aref locations;
		makearef(locations, isl.locations);
		wdmOpenIslandLocation(locations, loadedLocation.worldmap);
	}
}

void wdmOpenIslandLocation(aref locations, string name)
{
	//?????????????????? ?????? ????????????
	int num = GetAttributesNum(locations);
	for(int i = 0; i < num; i++)
	{
		aref loc = GetAttributeN(locations, i);
		if(!CheckAttribute(loc, "name")) continue;
		if(loc.name == name)
		{
			loc.visible = "true";
			if(CheckAttribute(loc, "label"))
			{
				loc.label.visible = "true";
			}
		}
	}
}

// WM NK wdmap/island interop 05-05-03
string wdmGetIslandNameFromID(string islandid)
{
	if(islandid == "") return islandid;
	int idx = FindIsland(islandid);
	if(idx >= 0 && idx < ISLANDS_QUANTITY)
	{
		ref island = GetIslandByIndex(idx);
		if(CheckAttribute(island,"worldmap")) return island.worldmap;
		return islandid;
	}
	return "";
}
// WM <--

// KK -->
void wdmSetIcon(string town, string new_name, int iNation)
{
	int island_idx, i, num;
	string island, wdmisland;
	aref wdmislandlocs, loc;

	if (!TownExist(town)) return;
	if (iNation >= NATIONS_QUANTITY) return;
	if (new_name == "" && iNation < -1) return;
	island = GetIslandIDFromTown(town);
	island_idx = FindIsland(island);
	if (island_idx < 0) return;
	wdmisland = wdmGetIslandNameFromID(island);
	//Boyer change for new label system
	if (CheckAttribute(worldMap, "islands." + wdmisland + ".locations")) {
        //Old label system
        makearef(wdmislandlocs, worldMap.islands.(wdmisland).locations);
        num = GetAttributesNum(wdmislandlocs);
        for (i = 0; i < num; i++) {
            loc = GetAttributeN(wdmislandlocs, i);
            if (!CheckAttribute(loc, "name")) continue;
            if (loc.name == town) {
                if (IsIslandDisabled(island)) {
                    trace("wdmSetIcon: island "+island+" is disabled.");
                    loc.modelName = "";
                    loc.label.text = "";
                    loc.label.icon = -1;
                    DeleteAttribute(loc, "real");
                } else {
                    if (new_name != "") loc.label.text = new_name;
                    loc.label.icon = wdmTownFlag(iNation);
                }
                //return;
                i = num;
            }
        }
        //New label system
        if (CheckAttribute(worldMap, "labels")) {
            makearef(wdmislandlocs, worldMap.labels));
            num = GetAttributesNum(wdmislandlocs);
            for (i = 0; i < num; i++) {
                loc = GetAttributeN(wdmislandlocs, i);
                if (!CheckAttribute(loc, "id")) continue;
                if (!CheckAttribute(loc, "type")) continue;
                if (!CheckAttribute(loc, "island")) continue;
                if (loc.type == "town" && loc.id == town && loc.island == wdmisland) {
                    if (IsIslandDisabled(island)) {
                        trace("wdmSetIcon: island "+island+" is disabled.");
                        //loc.modelName = "";
                        //loc.label.text = "";
                        //loc.label.icon = -1;
                        //DeleteAttribute(loc, "real");
                        //Boyer change
                        loc.text = "";
                        loc.icon = -1;
                    } else {
                        if (new_name != "") loc.text = new_name;
                        loc.icon = wdmTownFlag(iNation);
                    }
                    return;
                }
            }
        }
	}
}

int wdmTownFlag(int iNation)
{
	if (iNation == PERSONAL_NATION)	return 8;
	if (iNation >= 0 && iNation < NATIONS_QUANTITY) return GetFlagIndex(iNation);
	return -1;
}

bool wdmGetShorePos(string locid, ref x, ref z)
{
	x = 0.0;
	z = 0.0;
	int locidx = FindLocation(locid);
	if (locidx < 0) return false;
	string wrlmapcity = locid;
	if (CheckAttribute(&Locations[locidx], "worldmap")) wrlmapcity = Locations[locidx].worldmap;
	string island = Locations[locidx].island;
	aref arShores; makearef(arShores, worldMap.islands.(island).locations);
	int iNum = GetAttributesNum(arShores);
	for (int i = 0; i < iNum; i++)
	{
		aref arShore = GetAttributeN(arShores, i);
		if (CheckAttribute(arShore, "name") == true && arShore.name == wrlmapcity) {
			if (CheckAttribute(arShore, "ship.pos.x") && CheckAttribute(arShore, "ship.pos.z")) {
				x = stf(arShore.ship.pos.x);
				z = stf(arShore.ship.pos.z);
				return true;
			}
			break;
		}
	}
	return false;
}

void wdmInit()
{
	if(LoadSegment("worldmap\worldmap_init.c"))
	{
		wdmInitWorldMap();
		UnloadSegment("worldmap\worldmap_init.c");
	}
}
// <-- KK
