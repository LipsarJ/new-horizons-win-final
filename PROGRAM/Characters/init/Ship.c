void CreateShipCharacters(ref n)
{
	object chobj;
	ref ch;
	ref chRef = GetMainCharacter();

	makeref(ch, chobj);

			// ����� �����
	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name 	= XI_ConvertString("Crewmember");
	ch.lastname 	= "";
	ch.id		= "Crewmember_01"; // KK
	ch.model	= "bocman";
	ch.sound_type = "seaman";
	ch.sex = "man";
	ch.location	= "Seadogs";
	ch.location.group = "sleep";
	ch.location.locator = "bed1";
	ch.Dialog.Filename = "Crewmember_tired_dialog.c";
	ch.greeting = "Gr_Seaman";
	ch.sleep = true;
	ch.rank 	= 1;
	ch.nation = sti(chRef.nation);
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
	ch.money = "10";
	ch.quest.last_theme = "";
	LAi_SetLayType(ch);
	LAi_SetLoginTime(ch, 12.0, 24.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	AddGameCharacter(n, ch);

			//������� � �����
	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name 	= XI_ConvertString("Crewmember");
	ch.lastname 	= "";
	ch.id		= "Crewmember_02"; // KK
	ch.model	= "black_corsair";
	ch.sound_type = "seaman";
	ch.sex = "man";
	ch.location	= "Seadogs";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Crewmember_alc_dialog.c";
	ch.greeting = "Gr_Seaman";
	ch.rank 	= 1;
	ch.nation = sti(chRef.nation);
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
	ch.money = "10";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 12.0, 18.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	AddGameCharacter(n, ch);

			//������� � �����
	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name 	= XI_ConvertString("Crewmember");
	ch.lastname 	= "";
	ch.id		= "Crewmember_03"; // KK
	ch.model	= "man5";
	ch.sound_type = "seaman";
	ch.sex = "man";
	ch.location	= "Seadogs";
	ch.location.group = "sleep";
	ch.location.locator = "bed2";
	ch.Dialog.Filename = "Crewmember_tired_dialog.c";
	ch.greeting = "Gr_Seaman";
	ch.sleep = true;
	ch.nation = sti(chRef.nation);
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
	ch.money = "10";
	LAi_SetLayType(ch);
	LAi_SetLoginTime(ch, 8.0, 14.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	AddGameCharacter(n, ch);

			//Docker near Seagates of Redmond
	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name 	= XI_ConvertString("Crewmember");
	ch.lastname 	= "";
	ch.id		= "Crewmember_04"; // KK
	ch.model	= "man4";
	ch.model.sex = "man";
	ch.sound_type = "seaman";
	ch.location	= "Seadogs";
	ch.location.group = "rld";
	ch.location.locator = "loc1";
	ch.Dialog.Filename = "Crewmember_fight_dialog.c";
	ch.greeting = "Gr_Seaman";
	ch.nation = sti(chRef.nation);
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
	ch.money = "10";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 8.0, 12.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	AddGameCharacter(n, ch);

			//Robert Blewett
	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name 	= XI_ConvertString("Crewmember");
	ch.lastname 	= "";
	ch.id		= "Crewmember_05"; // KK
	ch.model	= "capitan";
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	ch.model.animation = "man";
	ch.location	= "Seadogs";
	ch.location.group = "rld";
	ch.location.locator = "aloc0";
	ch.Dialog.Filename = "Crewmember_fight_dialog.c";
	ch.greeting = "Gr_Seaman";
	ch.nation = sti(chRef.nation);
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
	ch.money = "10";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 12.0, 24.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	AddGameCharacter(n, ch);
/*
			//Robert Blewett
	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name 	= XI_ConvertString("Crewmember");
	ch.lastname 	= "";
	ch.id		= "Crewmember_06"; // KK
	ch.model	= "daniell1";
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.model.animation = "woman_sit";
	ch.location	= "Cabin1";
	ch.location.group = "sit";
	ch.location.locator = "sit4";
	ch.Dialog.Filename = "Crewmember_fight_dialog.c";
	ch.greeting = "trep\female-citizen\014.wav";
	ch.nation = sti(chRef.nation);
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
	ch.money = "10";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 1.0, 24.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	AddGameCharacter(n, ch);

// KK -->

	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name 	= XI_ConvertString("Crewmember");
	ch.lastname 	= "";
	ch.id		= "Crewmember_07";
	ch.model	= "man4";
	ch.model.sex = "man";
	ch.sound_type = "seaman";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Crewmember_fight_dialog.c";
	ch.greeting = "Gr_engcrew member1";
	ch.nation = sti(chRef.nation);
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
	ch.money = "10";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	AddGameCharacter(n, ch);


	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name 	= XI_ConvertString("Crewmember");
	ch.lastname 	= "";
	ch.id		= "Crewmember_08";
	ch.model	= "man4";
	ch.model.sex = "man";
	ch.sound_type = "seaman";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Crewmember_fight_dialog.c";
	ch.greeting = "Gr_engcrew member1";
	ch.nation = sti(chRef.nation);
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
	ch.money = "10";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	AddGameCharacter(n, ch);


	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name 	= XI_ConvertString("Crewmember");
	ch.lastname 	= "";
	ch.id		= "Crewmember_09";
	ch.model	= "man4";
	ch.model.sex = "man";
	ch.sound_type = "seaman";
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Crewmember_fight_dialog.c";
	ch.greeting = "Gr_engcrew member1";
	ch.nation = sti(chRef.nation);
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
	ch.money = "10";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	AddGameCharacter(n, ch);


	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name 	= XI_ConvertString("Crewmember");
	ch.lastname 	= "";
	ch.id		= "Crewmember_10";
	ch.model	= "man4";
	ch.model.sex = "man";
	ch.sound_type = "seaman";
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Crewmember_fight_dialog.c";
	ch.greeting = "Gr_engcrew member1";
	ch.nation = sti(chRef.nation);
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
	ch.money = "10";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	AddGameCharacter(n, ch);


	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name 	= XI_ConvertString("Crewmember");
	ch.lastname 	= "";
	ch.id		= "Crewmember_11";
	ch.model	= "man4";
	ch.model.sex = "man";
	ch.sound_type = "seaman";
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Crewmember_fight_dialog.c";
	ch.greeting = "Gr_engcrew member1";
	ch.nation = sti(chRef.nation);
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
	ch.money = "10";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	AddGameCharacter(n, ch);

	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name 	= XI_ConvertString("Crewmember");
	ch.lastname 	= "";
	ch.id		= "Crewmember_12";
	ch.model	= "man4";
	ch.model.sex = "man";
	ch.sound_type = "seaman";
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Crewmember_fight_dialog.c";
	ch.greeting = "Gr_engcrew member1";
	ch.nation = sti(chRef.nation);
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
	ch.money = "10";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	AddGameCharacter(n, ch);
// <-- KK
*/
}
