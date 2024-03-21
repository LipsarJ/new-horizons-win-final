void CreateMrMyth92Characters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

	int i;
	
	for (i=1; i<=10; i++)
{
	ch.id		= "CargoMan"+i;
	ch.model = "Offic_eng_17";
	ch.sex = "man";
	ch.model.animation = "carrier";
	ch.sound_type = "male_citizen";
	ch.nation = ENGLAND;
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
	LAi_SetImmortal(ch, true);
	AddGameCharacter(n, ch);
}
}