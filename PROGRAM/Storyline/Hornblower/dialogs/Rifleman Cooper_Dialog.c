//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------������ ������ - ������ �������
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
//			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

	
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			if(CheckQuestAttribute("Soldier_Company", "Foot"))
			{	
//			PlaySound("VOICE\ENGLISH\Cooper01.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
			}
			else
			{	
//			PlaySound("VOICE\ENGLISH\Cooper01.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit";
			}
		break;

		case "Pick_Lock_Chat":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Pick_Lock_Chat2";
		break;

		case "Pick_Lock_Chat2":
//			PlaySound("VOICE\ENGLISH\Cooper02.wav");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Pick_Lock_Chat3";
		break;

		case "Pick_Lock_Chat3":
//			PlaySound("VOICE\ENGLISH\Cooper03.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Pick_Lock_Chat4";
		break;

		case "Pick_Lock_Chat4":
//			PlaySound("VOICE\ENGLISH\Cooper04.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Exit_Pick_Lock_Chat";
		break;

		case "Exit_Pick_Lock_Chat":
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Church_Lock_Open");
			DialogExit();
		break;

		case "Dont_know_much_French":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Dont_know_much_French2";
		break;

		case "Dont_know_much_French2":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Exit_Dont_know_much_French";
		break;

		case "Exit_Dont_know_much_French":
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("A_French_Prison_waits");
			DialogExit();
		break;

		case "Escaping_to_ship":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Exit";
		break;

		case "Here_to_help":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit";
		break;
		
	}
}
