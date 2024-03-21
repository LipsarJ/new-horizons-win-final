void CreateCarriers(ref loc)
{
if(LAi_IsCapturedLocation || !CheckAttribute(loc, "townsack") || !CheckAttribute(loc, "carrier") || !CheckAttribute(loc, "type"))
{
return;
}
if(loc.type != "town" && loc.type != "plantation")return;
int iCitizensQuantity, iModel;
ref chr;
int iChar, i, iSex;
string slai_group, locatorName, sType;
slai_group = GetNationNameByType(GetLocationNation(loadedLocation))+ "_citizens"; 
int iTemp;
int iQtyCarrier = rand(2)+ 2;
string CarrierName[10];
CarrierName[0] = "CarrierBag1";
CarrierName[1] = "CarrierBag2";
CarrierName[2] = "CarrierBarrel1";
CarrierName[3] = "CarrierBarrel2";
CarrierName[4] = "CarrierBarrelTop1";
CarrierName[5] = "CarrierBarrelTop2";
CarrierName[6] = "CarrierBottle1";
CarrierName[7] = "CarrierBottle2";
CarrierName[8] = "CarrierChest1";
CarrierName[9] = "CarrierChest2";
for(i=iQtyCarrier; i>0; i--)
{
iSex = 1;
while(iSex == 1)
{
iTemp = rand(9);
if(CarrierName[iTemp] != "")iSex = 0;
}
chr = characterFromID("CargoMan"+i);
chr.model = CarrierName[iTemp];
chr.nation = GetLocationNation(loadedLocation);
SetRandomNameToCharacter(chr);
CarrierName[iTemp] = "";
LAi_SetImmortal(chr, true);
LAi_SetLoginTime(chr, 7.0, 20.0);
LAi_SetCitizenType(chr);
ChangeCharacterAddressGroup(chr, pchar.location, "carrier", LAi_FindFreeRandomLocator("carrier"));
}
}