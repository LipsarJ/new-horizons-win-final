//Boyer change
#define ISLAND_DISCOVERY_DISTANCE 2000.0

object wdmLoginToSea;
object wdm_fader;
bool wdmLockReload = false;
bool wdmDoCheck = false;

void wdmReloadToSea()
{
	if (wdmDoCheck) {
		wdmDoCheck = false;
		return;
	}
//	ResetTimeToNormal();//MAXIMUS: removes time-acceleration and sets normal time

trace("wdmReloadToSea");
trace("worldMap.zeroX " + worldMap.zeroX);
trace("worldMap.zeroZ " + worldMap.zeroZ);
trace("worldMap.island " + worldMap.island);
trace("worldMap.island.x " + worldMap.island.x);
trace("worldMap.island.z " + worldMap.island.z);
trace("worldMap.playerShipX " + worldMap.playerShipX);
trace("worldMap.playerShipZ " + worldMap.playerShipZ);												  
	if(sti(GetStorylineVar(FindCurrentStoryline(), "DISABLE_TIPS")) < 1) SetReloadNextTipsImage(); // JRH
	if(wdmLockReload)
	{
		wdmDisableTornadoGen = true;
		return;
	}

	ref Pchar = GetMaincharacter();

	CreateILogAndActions(LOG_FOR_SEA); // KK

	worldMap.encounter.type = "";

	DeleteAttribute(&wdmLoginToSea, ""); //Clear login object
	//Reload to island
	float baseX, baseZ;
	//Player ship coordinates
	worldMap.playerShipUpdate = "";
	WdmAddPlayerGroup();

// KK -->
	ref wrldMap; makeref(wrldMap, WorldMap);
	if (CheckAttribute(wrldMap, "FromCoast")) {
		wdmLoginToSea.FromCoast = sti(wrldMap.FromCoast);
		DeleteAttribute(wrldMap, "FromCoast");
	}
	// Encounters
	int i;
	string grp;
	float psX = MakeFloat(worldMap.playerShipX);
	float psZ = MakeFloat(worldMap.playerShipZ);
	float plsX = MakeFloat(wdmLoginToSea.playerGroup.x);
	float plsZ = MakeFloat(wdmLoginToSea.playerGroup.z);
	float encX, encZ;
	if (CheckAttribute(wrldMap, "QuestToSeaLogin") == false || sti(wrldMap.QuestToSeaLogin) == false) {
		int numEncounters = wdmGetNumberShipEncounters();
		bool isShipEncounterType = false;
		for(i = 0; i < numEncounters; i++)
		{
			if(wdmSetCurrentShipData(i))
			{
				if(MakeInt(worldMap.encounter.select) == 0) continue;
				//Boyer add to fix encounters
				string encStringID = worldMap.encounter.id;
                if(encStringID == "") continue;
                encStringID = "encounters." + encStringID + ".encdata";
                if(CheckAttribute(&worldMap, encStringID) == 0) continue;
                int mapEncSlot = FindFreeMapEncounterSlot();
                if(mapEncSlot < 0) continue;
                ref mapEncSlotRef = GetMapEncounterRef(mapEncSlot);
                aref encDataForSlot;
                makearef(encDataForSlot, worldMap.(encStringID));
                CopyAttributes(mapEncSlotRef, encDataForSlot);
                //End Boyer add
				isShipEncounterType = true;
				/*
				// boal ����� ��������� ������, � �� � ���������� ������� -->
				wdmLoginToSea.island = "";
				wdmCurrentIsland = WDM_NONE_ISLAND;
				// boal ����� ��������� ������, � �� � ���������� ������� <--
				*/
				grp = "group" + i;
				encX = MakeFloat(worldMap.encounter.x);
				encZ = MakeFloat(worldMap.encounter.z);
				wdmLoginToSea.encounters.(grp).x = plsX + (encX - psX)*WDM_MAP_TO_SEA_ENCOUNTERS_SCALE;
				wdmLoginToSea.encounters.(grp).z = plsZ + (encZ - psZ)*WDM_MAP_TO_SEA_ENCOUNTERS_SCALE;
				wdmLoginToSea.encounters.(grp).ay = worldMap.encounter.ay;
				//wdmLoginToSea.encounters.(grp).type = worldMap.encounter.type;
				//Boyer add
				wdmLoginToSea.encounters.(grp).type = mapEncSlot;
				encStringID = worldMap.encounter.id;
                encStringID = "encounters." + encStringID;
				if(CheckAttribute(&worldMap, encStringID + ".quest") == 0)
                {
                    worldMap.(encStringID).needDelete = "Reload delete non quest encounter";
                }
			}
		}
	}
// <-- KK
    //Boyer add
    wdmReleaseEncounters();
	WdmStormEncounter();
	worldMap.deleteUpdate = "";
	SendMessage(&worldMap, "l", MSG_WORLDMAP_CREATEENC_RELEASE);
	//Weather
	worldMap.info.updateinfo = "";
	//wdmLoginToSea.storm = worldMap.info.playerInStorm;
	//Fade out
	SetEventHandler("FaderEvent_StartFade", "WdmStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "WdmEndFade", 0);
	wdm_fader.thisWorldMapFader = "";
	CreateEntity(&wdm_fader, "fader");
	if(IsEntity(wdm_fader) == 0) Trace("Fader not created!!!");
	float fadeOutTime = 0.5;
	SendMessage(&wdm_fader, "lfl", FADER_OUT, fadeOutTime, true);
	SendMessage(&wdm_fader, "l", FADER_STARTFRAME);
// KK -->

	SetNextWeather("Clear");
	string imageName = "sea.tga";
	if (CheckAttribute(&worldMap, "QuestToSeaLogin") == true && sti(worldMap.QuestToSeaLogin) == true) {
		DeleteAttribute(&worldMap, "QuestToSeaLogin");
		if (CheckAttribute(&questToSeaLoginer, "Storm") == true && sti(questToSeaLoginer.Storm) == true) {
			wdmLoginToSea.storm = true;
			if (CheckAttribute(&questToSeaLoginer, "Tornado") == true && sti(questToSeaLoginer.Tornado) == true) {
				imageName = "Twister.tga";
				wdmLoginToSea.tornado = 1;
				SetNextWeather("Heavy Storm");
			} else {
				imageName = "Storm.tga";
				wdmLoginToSea.tornado = 0;
				SetNextWeather("Stormy");
			}
		}
	} else {
		//Trace("worldMap.encounter.type = " + worldMap.encounter.type);
		if (isShipEncounterType) imageName = "Battle.tga";
		if (bShipMutiny) imageName = "ShipMutiny.tga"; // KK
		if (wdmLoginToSea.storm != "0") {
			imageName = "Storm.tga";
			wdmLoginToSea.tornado = 0;
			SetNextWeather("Stormy");
			if(wdmTornadoGenerator()) {
				imageName = "Twister.tga";
				wdmLoginToSea.tornado = 1;
				SetNextWeather("Heavy Storm");
			}
		}
	}
	wdmLoginToSea.imageName = imageName;
	SendMessage(&wdm_fader, "ls", FADER_PICTURE, FindReloadPicture(imageName));
// <-- KK
	wdmDisableTornadoGen = true;
}

// VANO function: return sea coordinates
void WdmPrepareMapForAbordage(aref arPos)
{
	float psX = MakeFloat(worldMap.playerShipX);
	float psZ = MakeFloat(worldMap.playerShipZ);
	if(worldMap.island != WDM_NONE_ISLAND)
	{
		//Island
		wdmLoginToSea.island = worldMap.island;
		float ix = MakeFloat(worldMap.island.x);
		float iz = MakeFloat(worldMap.island.z);
		int scale = WDM_MAP_TO_SEA_SCALE;
		if (worldMap.island == "Cuba" || worldMap.island == "Gaity")
		{
			scale = 75;
		}
		arPos.x = (psX - ix)*scale;
		arPos.z = (psZ - iz)*scale;
		arPos.y = worldMap.playerShipAY;
		worldMap.zeroX = ix;
		worldMap.zeroZ = iz;
	}else{
		//no Island
		wdmLoginToSea.island = "";
		//Player ship
		arPos.x = 0;
		arPos.z = 0;
		arPos.y = worldMap.playerShipAY;
		worldMap.zeroX = worldMap.playerShipX;
		worldMap.zeroZ = worldMap.playerShipZ;
	}
}

void WdmAddPlayerGroup()
{
	float psX = MakeFloat(worldMap.playerShipX);
	float psZ = MakeFloat(worldMap.playerShipZ);
	if(worldMap.island != WDM_NONE_ISLAND)
	{
		//Island
		wdmLoginToSea.island = worldMap.island;
		float ix = MakeFloat(worldMap.island.x);
		float iz = MakeFloat(worldMap.island.z);
		int scale = WDM_MAP_TO_SEA_SCALE;
		if (worldMap.island == "Cuba" || worldMap.island == "Gaity")
		{
			scale = CUBA_MAP_SCALE;
		}
		if (worldMap.island == "SantaCatalina" || worldMap.island == "PortoBello" || worldMap.island == "Colombia")
		{
			scale = CONTINENT_SCALE;
		}
		wdmLoginToSea.playerGroup.x = (psX - ix)*scale;
		wdmLoginToSea.playerGroup.z = (psZ - iz)*scale;
		wdmLoginToSea.playerGroup.ay = worldMap.playerShipAY;
		worldMap.zeroX = ix;
		worldMap.zeroZ = iz;
	}else{
		//no Island
		wdmLoginToSea.island = "";
		//Player ship
		wdmLoginToSea.playerGroup.x = 0;
		wdmLoginToSea.playerGroup.z = 0;
		wdmLoginToSea.playerGroup.ay = worldMap.playerShipAY;
		worldMap.zeroX = worldMap.playerShipX;
		worldMap.zeroZ = worldMap.playerShipZ;
	}
}

void WdmStartFade()
{
	PauseAllSounds();
// NK -->
	ref mc = GetMainCharacter();

	// CheckAttribute fix by dchaley sep-12-2004 // KK -->
	if (ENABLE_EXTRA_SOUNDS == 1 && CheckAttribute(mc, "ShipEnc") == true) {
		switch (mc.ShipEnc)
		{
			case "ship":  PlaySound("#ship_ahoy");        break; // added by KAM after build 11
			case "enemy": PlaySound("#clear_for_action"); break; // added by KAM after build 11
		}
	}
	// <-- KK

	mc.ShipEnc = "none";

// NK <--
	wdmDisableTornadoGen = true;
	wdmDisableRelease = false;
	//Delete EventHandler
	DelEventHandler("FaderEvent_StartFade", "WdmStartFade");
	//Delete entity
	worldMap.playerShipUpdate = "";
	DeleteClass(&worldMap);
	worldMap.isLoaded = "false";
	DeleteWmInterface();
}

void WdmEndFade()
{
	int a = GetEventData();
	wdm_fader = GetEventData();

	wdmDisableRelease = true;
	//Delete EventHandler
	DelEventHandler("FaderEvent_EndFade", "WdmEndFade");
	//Switch to sea
	ReloadProgressStart();
	SeaLogin(&wdmLoginToSea);
	LayerAddObject(SEA_REALIZE, &wdm_fader, -1);
	ReloadProgressEnd();
}

void QuitFromWorldMap()
{
	//Fade out
	SetEventHandler("FaderEvent_StartFade", "WdmStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "WdmEndFadeA", 0);
	wdm_fader.thisWorldMapFader = "";
	CreateEntity(&wdm_fader, "fader");
	if(IsEntity(wdm_fader) == 0) trace("Fader not created!!!");
	float fadeOutTime = 0.5;
	SendMessage(&wdm_fader, "lfl", FADER_OUT, fadeOutTime, true);
	SendMessage(&wdm_fader, "l", FADER_STARTFRAME);
}

void WdmEndFadeA()
{
	// Faradin Fix -->
	wdmDisableRelease = true;
	//Delete EventHandler
	DelEventHandler("FaderEvent_EndFade", "WdmEndFadeA");
	//Switch to sea
	Event("QuitFromWorldMap"); //uncommented
	// Faradin Fix <--
}

bool WdmAddEncountersData()
{
	bool isShipEncounter = false;
	ReleaseMapEncounters();
	int numEncounters = wdmGetNumberShipEncounters();
	float mpsX = MakeFloat(worldMap.playerShipX);
	float mpsZ = MakeFloat(worldMap.playerShipZ);
	float wpsX = MakeFloat(wdmLoginToSea.playerGroup.x);
	float wpsZ = MakeFloat(wdmLoginToSea.playerGroup.z);
	for(int i = 0; i < numEncounters; i++)
	{
		if(wdmSetCurrentShipData(i))
		{
			if(MakeInt(worldMap.encounter.select) == 0) continue;
			string encStringID = worldMap.encounter.id;
			if(encStringID == "") continue;
			encStringID = "encounters." + encStringID + ".encdata";
			if(CheckAttribute(&worldMap, encStringID) == 0) continue;
			int mapEncSlot = FindFreeMapEncounterSlot();
			if(mapEncSlot < 0) continue;
			ref mapEncSlotRef = GetMapEncounterRef(mapEncSlot);
			aref encDataForSlot;
			makearef(encDataForSlot, worldMap.(encStringID));
			CopyAttributes(mapEncSlotRef, encDataForSlot);
			isShipEncounter = true;
			string grp; grp = "group" + i;
			float encX = MakeFloat(worldMap.encounter.x);
			float encZ = MakeFloat(worldMap.encounter.z);
			wdmLoginToSea.encounters.(grp).x = wpsX + (encX - mpsX)*WDM_MAP_TO_SEA_ENCOUNTERS_SCALE;//WDM_MAP_TO_SEA_SCALE;
			wdmLoginToSea.encounters.(grp).z = wpsZ + (encZ - mpsZ)*WDM_MAP_TO_SEA_ENCOUNTERS_SCALE;//WDM_MAP_TO_SEA_SCALE;

			//JA
			wdmLoginToSea.encounters.(grp).deltax = (encX - mpsX)*WDM_MAP_TO_SEA_ENCOUNTERS_SCALE;//WDM_MAP_TO_SEA_SCALE;
			wdmLoginToSea.encounters.(grp).deltaz = (encZ - mpsZ)*WDM_MAP_TO_SEA_ENCOUNTERS_SCALE;//WDM_MAP_TO_SEA_SCALE;

			wdmLoginToSea.encounters.(grp).ay = worldMap.encounter.ay;
			wdmLoginToSea.encounters.(grp).type = mapEncSlot;
			wdmLoginToSea.encounters.(grp).id = worldMap.encounter.id;
			encStringID = worldMap.encounter.id;
			encStringID = "encounters." + encStringID;
			if(CheckAttribute(&worldMap, encStringID + ".quest") == 0)
			{
				worldMap.(encStringID).needDelete = "Reload delete non quest encounter";
			}
		}
	}
	return isShipEncounter;
}

void WdmStormEncounter()
{
	wdmLoginToSea.storm = worldMap.playerInStorm;
	if(MakeInt(wdmLoginToSea.storm) != 0)
	{
		wdmLoginToSea.tornado = worldMap.stormWhithTornado;
		// SetNextWeather("Heavy Storm");
	}else{
		wdmLoginToSea.tornado = "0";
		// SetNextWeather("Stormy");
	}

	//wdmLoginToSea.tornado = "1";

	if(CheckAttribute(&worldMap, "stormId") != 0)
	{
		if(worldMap.stormId != "")
		{
			string encStringID = worldMap.stormId;
			encStringID = "encounters." + encStringID;
			worldMap.(encStringID).needDelete = "Reload delete storm";
		}
	}
}

// KK -->
int wdmToLandIdx = -1;
string wdmToLandGroup = "";
string wdmToLandLocator = "";
string wdmToLandShipLocation = "";

void wdmReloadToLand(string locationID, string group, string locator, string ship_location)
{
	if (!IsEntity(&worldMap)) return;
	wdmToLandIdx = FindLocation(locationID);
	if (wdmToLandIdx < 0) return;
	CreateILogAndActions(LOG_FOR_LAND);
	wdmToLandGroup = "reload";
	if (group != "") wdmToLandGroup = group;
	wdmToLandLocator = locator;
	wdmToLandShipLocation = ship_location;

	if(sti(GetStorylineVar(FindCurrentStoryline(), "DISABLE_TIPS")) < 1) SetReloadNextTipsImage(); // JRH

	//Fade out
	SetEventHandler("FaderEvent_StartFade", "WdmToLandStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "WdmToLandEndFade", 0);
	wdm_fader.thisWorldMapFader = "";
	CreateEntity(&wdm_fader, "fader");
	if(IsEntity(wdm_fader) == 0) Trace("Fader not created!!!");
	float fadeOutTime = 0.5;
	SendMessage(&wdm_fader, "lfl", FADER_OUT, fadeOutTime, true);
	SendMessage(&wdm_fader, "l", FADER_STARTFRAME);
	if (CheckAttribute(&Locations[wdmToLandIdx], "image")) SendMessage(&wdm_fader, "ls", FADER_PICTURE, FindReloadPicture(Locations[wdmToLandIdx].image));

	PauseAllSounds();
	//ResetSoundScheme();
	ResetSound();
}

void WdmToLandStartFade()
{
	PauseAllSounds();
// NK -->
	ref mc = GetMainCharacter();

	mc.ShipEnc = "none";

	mc.location = Locations[wdmToLandIdx].id;
	mc.location.group = wdmToLandGroup;
	mc.location.locator = wdmToLandLocator;
	if (wdmToLandShipLocation != "") {
		mc.location.from_sea = wdmToLandShipLocation;
		SetFleetInTown(GetTownIDFromLocID(wdmToLandShipLocation), "pchar");
	}
	//Delete EventHandler
	DelEventHandler("FaderEvent_StartFade", "WdmToLandStartFade");
	//Delete entity
	worldMap.playerShipUpdate = "";
	DeleteClass(&worldMap);
	worldMap.isLoaded = "false";
}

void WdmToLandEndFade()
{
	wdmDisableRelease = true;
	//Delete EventHandler
	DelEventHandler("FaderEvent_EndFade", "WdmToLandEndFade");
	SendMessage(&wdm_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
	//Switch to sea
	ReloadProgressStart();
	//SeaLogin(&wdmLoginToSea);
	if (!LoadLocation(&Locations[wdmToLandIdx])) {
		trace("wdmReloadToLand: Location <" + Locations[wdmToLandIdx].id + "> loading failed");
	}
	lockedReloadLocator = "";
	chrWaitReloadLocator = "";
	chrWaitReloadIsNoLink = false;
	//LayerAddObject(SEA_REALIZE, &wdm_fader, -1);
	ReloadProgressEnd();
	PostEvent("LoadSceneSound", 500);
}
// <-- KK
