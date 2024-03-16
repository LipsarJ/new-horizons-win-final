void CreateQuebradasCostillasCharacters(ref n)
{
	object chobj;
	ref ch;
	makeref(ch, chobj);

	ch.old.name = "Ines";
	ch.old.lastname = "Diaz";
	ch.name = TranslateString("","Ines");
	ch.lastname = TranslateString("","Diaz");
	ch.id		= "Ines Diaz";
	ch.model	= "Oldwoman";
	ch.sex = "woman";
	ch.location	= "QC_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Ines Diaz_dialog.c";
	ch.greeting = "Gr_Ines Diaz";
	ch.nation = PIRATE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	ch.quest.about = "0";
	ch.quest.rheims = "0";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	AddGameCharacter(n, ch);

	// Skull
	ch.old.name = "Skull";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Skull");
	ch.lastname = "";
	ch.id		= "Isenbrandt Jurcksen";
	ch.model	= "Skull";
	ch.sex = "man";
	ch.location	= "QC_residence";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Skull_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.rank 	= 20;
	ch.reputation = "25";
	ch.experience = "250000";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "6";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "7";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "2";
	ch.money = "10000";
	ch.Ship.Name = "Dud";
	ch.ship.type = "PiratFrigateSup"; // PRS3
	// done by setbaseship - NK 05-04-09 ch.ship.cargo.goods.bombs = 1000;
	ch.Ship.Stopped = true;
	//KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_warrior_SetStay(ch, true);
	Lai_SetImmortal(ch, true);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 160.0, 160.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	ch.greeting = "Gr_Isenbrandt Jurcksen";
	AddGameCharacter(n, ch);
}
