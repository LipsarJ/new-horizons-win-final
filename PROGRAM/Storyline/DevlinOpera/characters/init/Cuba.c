void CreateCubaCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

	ch.old.name = "Rocoso";
	ch.old.lastname = "Balboa";
	ch.name = TranslateString("", "Rocoso");
	ch.lastname = TranslateString("", "Balboa");
	ch.id		= "Rocoso Balboa";
	ch.model = "corsair1_4";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	GiveItem2Character(ch, "bladeC2");
	ch.equip.blade = "bladeC2";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Rocoso Balboa_dialog.c";
	ch.greeting = "Gr_Balboa";
	ch.nation = SPAIN;
	ch.rank 	= 3;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.questchar = true;
	ch.quest.meeting = "0";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Don Evaristo";
	ch.old.lastname = "Torres";
	ch.name = TranslateString("", "Don Evaristo");
	ch.lastname = TranslateString("", "Torres");
	ch.id		= "Don Evaristo Torres";
	ch.model = "Huber_Spa2_17";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	GiveItem2Character(ch, "bladeC2");
	ch.equip.blade = "bladeC2";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Don Evaristo Torres_dialog.c";
	ch.greeting = "Gr_DonEvaristo";
	ch.nation = SPAIN;
	ch.rank 	= 5;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.questchar = true;
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);

//----------------------------------------------------------------

	ch.old.name = "Juan";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Juan");
	ch.lastname = "";
	ch.id		= "Juan";
	ch.model = "Sailor6";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Juan_dialog.c";
	ch.greeting = "";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.quest.meeting = "0";
	LAi_SetLayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Paolo";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Paolo");
	ch.lastname = "";
	ch.id		= "Paolo";
	ch.model = "Sailor4";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Paolo_dialog.c";
	ch.greeting = "";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Jorge";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Jorge");
	ch.lastname = "";
	ch.id		= "Jorge";
	ch.model = "man6";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Jorge_dialog.c";
	ch.greeting = "";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.quest.meeting = "0";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Ricardo";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Ricardo");
	ch.lastname = "";
	ch.id		= "Ricardo";
	ch.model = "Sailor19";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Ricardo_dialog.c";
	ch.greeting = "";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Pedro";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pedro");
	ch.lastname = "";
	ch.id		= "Pedro";
	ch.model = "Sailor14";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Pedro_dialog.c";
	ch.greeting = "";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Jose";
	ch.old.lastname = "Zugarro";
	ch.name = TranslateString("", "Jose");
	ch.lastname = TranslateString("", "Zugarro");
	ch.id		= "Fake Storeman";
	ch.model = "hub_spa3";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Fake Storeman_dialog.c";
	ch.greeting = "Gr_Emiliano Rionda";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Subteniente";
	ch.old.lastname = "Chorizo";
	ch.name = TranslateString("", "Subteniente");
	ch.lastname = TranslateString("", "Chorizo");
	ch.id		= "Chorizo";
	ch.model = "Offic_spa"; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	GiveItem2Character(ch, "blade15");
	ch.equip.blade = "blade15";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Chorizo_dialog.c";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.quest.meeting = "0";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Dragan";
	ch.old.lastname = "van Mourik";
	ch.name = TranslateString("", "Dragan");
	ch.lastname = TranslateString("", "van Mourik");
	ch.id		= "Dragan van Mourik";
	ch.model = "AnimistEdmundo";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Dragan van Mourik_dialog.c";
	ch.greeting = "";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.quest.meeting = "0";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);

//------------------------------ BANDITS

	ch.old.name = "Kevin";
	ch.old.lastname = "Poor";
	ch.name = TranslateString("", "Kevin");
	ch.lastname = TranslateString("", "Poor1");
	ch.id		= "Kevin Poor";
	ch.model = "Pir_cap4";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	GiveItem2Character(ch, "blade33");
	ch.equip.blade = "blade33";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Kevin Poor_dialog.c";
	ch.greeting = "";
	ch.nation = PIRATE;
	ch.rank 	= 5;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.questchar = true;
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);

	ch.old.name = "Grunk";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Grunk");
	ch.lastname = "";
	ch.id		= "Grunk";
	ch.model = "mask";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	GiveItem2Character(ch, "blade5");
	ch.equip.blade = "blade5";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "";
	ch.greeting = "";
	ch.nation = PIRATE;
	ch.rank 	= 1;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.questchar = true;
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);

	ch.old.name = "Flobb";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Flobb");
	ch.lastname = "";
	ch.id		= "Flobb";
	ch.model = "mask_2";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	GiveItem2Character(ch, "blade5");
	ch.equip.blade = "blade5";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "";
	ch.greeting = "";
	ch.nation = PIRATE;
	ch.rank 	= 1;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.questchar = true;
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);
}
