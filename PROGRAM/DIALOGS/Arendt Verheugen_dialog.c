void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	
	switch(Dialog.CurrentNode)
	{
	// -----------------------------------|����� ������ - ������ �������
		case "First time":
			Dialog.defAni = "Gov_Dialog_1";
			Dialog.ani = "Gov_Dialog_2";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			if(TradeCheck(PChar, NPChar, true)) { // NK
				if(NPChar.quest.meeting == "0")
				{
					d.Text = TimeGreeting() + DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1];
					Link.l1 = DLG_TEXT[2] + GetMyFullName(PChar) + DLG_TEXT[3] + GetMyShipNameShow(PChar) + DLG_TEXT[4];
					Link.l1.go = "meeting";
					NPChar.quest.meeting = "1"; 
				}
				else
				{
					d.Text = TimeGreeting() + DLG_TEXT[5] + GetMyName(Pchar) + DLG_TEXT[6] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[7];
					Link.l1 = DLG_TEXT[8];
					Link.l1.go = "Shipyard";
					Link.l2 = DLG_TEXT[9];
					Link.l2.go = "quest lines";
					Link.l99 = DLG_TEXT[10];
					Link.l99.go = "exit";
				}
			// NK -->
			}
			else
			{
				dialog.text = DLG_TEXT[27] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[28];
				Link.l1 = DLG_TEXT[29];
				Link.l1.go = "exit";
			}
			// NK <--
		break;

		case "Meeting":
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12] + GetMyName(NPChar) +DLG_TEXT[13];
			Link.l1.go = "Shipyard";			
			Link.l2 = DLG_TEXT[14];
			Link.l2.go = "quest lines";
			Link.l3 = DLG_TEXT[15];
			Link.l3.go = "exit";
		break;

		case "quest lines":
			d.Text = DLG_TEXT[16]+ GetMyName(PChar) + DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "no quest";
		break;

		case "No quest":
			d.Text = DLG_TEXT[19] + GetMyName(Pchar) + DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "Shipyard";
			Link.l2 = DLG_TEXT[22];
			Link.l2.go = "exit";
		break;

		case "shipyard":
			d.Text = DLG_TEXT[30] + DLG_TEXT[23];	// ccc 15oct04 shipyard waiting : changed by MAXIMUS
			Link.l9 = DLG_TEXT[31];	// ccc
			Link.l9.go = "exit";	//ccc
			Link.l1 = DLG_TEXT[24];
			Link.l1.go = "SHIPYARD_interface";
		break;

		case "SHIPYARD_interface":
			Diag.CurrentNode = Diag.TempNode;
			
			if (npchar.quest.Meeting != lastspeak_date)
			{
				FillShipsList(&NPChar); // NK

				npchar.quest.Meeting = lastspeak_date;
			}

			DialogExit();
			LaunchShipyard(npchar);
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}
