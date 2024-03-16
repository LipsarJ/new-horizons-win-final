//#include "DIALOGS\Augusto Queiroz_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------������ ������ - ������ �������
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[0];
			        link.l1 = DLG_TEXT[1];
			        link.l1.go = "exit";
                       
                        break;

                       case "begin_1":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[2];
			        link.l1 = DLG_TEXT[3];
			        link.l1.go = "begin_2";

                        break;

                       case "begin_2":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[4];
			        link.l1 = DLG_TEXT[5];
			        link.l1.go = "begin_3";                    

                        break;


                       case "begin_3":
       
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[6];
			        link.l1 = DLG_TEXT[7];
			        link.l1.go = "exit";
                               AddDialogExitQuest("Falar_Soares");
                        break;

                       case "begin_4":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[8];
			        link.l1 = DLG_TEXT[9];
			        link.l1.go = "exit";
                               AddDialogExitQuest("Search_Campos");                            
                        break;

                       case "begin_5":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[10];
			        link.l1 = DLG_TEXT[11];
			        link.l1.go = "begin_6";                            
                        break;
						
                       case "begin_6":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[12];
			        link.l1 = DLG_TEXT[13];
			        link.l1.go = "exit";
                                AddDialogExitQuest("Search_Campos_Jungle");
                        break;

                       case "begin_7":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[14];
			        link.l1 = DLG_TEXT[15];
			        link.l1.go = "exit";
                                AddDialogExitQuest("Campos_Morto");
                        break;

                       case "begin_8":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[16];
			        link.l1 = DLG_TEXT[17];
			        link.l1.go = "begin_9";                          
                        break;

                       case "begin_9":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[18];
			        link.l1 = DLG_TEXT[19];
			        link.l1.go = "exit";
                                AddDialogExitQuest("Queiroz_Adeus");
                        break;

                       case "begin_10":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[20];
			        link.l1 = DLG_TEXT[21];
			        link.l1.go = "begin_11";

                        break;

                       case "begin_11":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[22];
			        link.l1 = DLG_TEXT[23];
			        link.l1.go = "begin_12";                    

                        break;

                       case "begin_12":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[24];
			        link.l1 = DLG_TEXT[25];
			        link.l1.go = "begin_13";

                        break;

                       case "begin_13":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[26];
			        link.l1 = DLG_TEXT[27];
			        link.l1.go = "begin_14";                    

                        break;	

                       case "begin_14":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[28];
			        link.l1 = DLG_TEXT[29];
			        link.l1.go = "exit";
                                AddDialogExitQuest("aller_cartagena");
                        break;

                       case "begin_15":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[30];
			        link.l1 = DLG_TEXT[31];
			        link.l1.go = "begin_16";                    

                        break;	

                       case "begin_16":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[32];
			        link.l1 = DLG_TEXT[33];
			        link.l1.go = "exit";
                                AddDialogExitQuest("aller_bateau2");
                        break;

                       case "begin_17":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[34];
			        link.l1 = DLG_TEXT[35];
			        link.l1.go = "begin_18";                    

                        break;	

                       case "begin_18":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[36];
			        link.l1 = DLG_TEXT[37];
			        link.l1.go = "exit";
                                AddDialogExitQuest("return_montavez");
                        break;

                       case "begin_19":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[38];
			        link.l1 = DLG_TEXT[39];
			        link.l1.go = "begin_20";                       
                        break;		

                       case "begin_20":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[40];
			        link.l1 = DLG_TEXT[41];
			        link.l1.go = "exit";
                                AddDialogExitQuest("last_meet_with_governor");
                        break;

                       case "begin_21":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[42];
			        link.l1 = DLG_TEXT[43];
			        link.l1.go = "exit";
                                AddDialogExitQuest("operation_dierman");
                        break;

                       case "begin_22":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[44];
			        link.l1 = DLG_TEXT[45];
			        link.l1.go = "begin_23";                       
                        break;		

                       case "begin_23":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[46];
			        link.l1 = DLG_TEXT[0];
			        link.l1.go = "exit";
                                AddDialogExitQuest("before_cartagena_puzzle2");
                        break;

                       case "begin_24":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[47];
			        link.l1 = DLG_TEXT[48];
			        link.l1.go = "exit"; 
                               AddDialogExitQuest("before_cartagena_puzzle4");					
                        break;		

                       case "begin_25":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[49];
			        link.l1 = DLG_TEXT[50];
			        link.l1.go = "begin_26";
                               
                        break;

                       case "begin_26":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[51];
			        link.l1 = DLG_TEXT[52];
			        link.l1.go = "exit"; 
                               AddDialogExitQuest("cartagena_puzzle_start");					
                        break;

                       case "begin_27":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[53];
			        link.l1 = DLG_TEXT[54];
			        link.l1.go = "begin_28";
                               
                        break;

                       case "begin_28":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[55];
			        link.l1 = DLG_TEXT[56];
			        link.l1.go = "begin_29";
                               
                        break;

                       case "begin_29":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[57];
			        link.l1 = DLG_TEXT[58];
			        link.l1.go = "exit";
            				AddDialogExitQuest("before_cartagena_puzzle7A");		//JRH							
                        break;

                       case "begin_30":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[59];
			        link.l1 = DLG_TEXT[60];
			        link.l1.go = "begin_31";
                               
                        break;

                       case "begin_31":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[61];
			        link.l1 = DLG_TEXT[62];
			        link.l1.go = "exit"; 
                               AddDialogExitQuest("tunnel_to_fort2");					
                        break;

                       case "begin_32":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[63];
			        link.l1 = DLG_TEXT[64];
			        link.l1.go = "exit"; 
                               AddDialogExitQuest("tunnel_to_fort5");					
                        break;

                       case "begin_33":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[65];
			        link.l1 = DLG_TEXT[66];
			        link.l1.go = "exit"; 
                               AddDialogExitQuest("inside_fort2");					
                        break;

                       case "begin_34":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[67];
			        link.l1 = DLG_TEXT[68];
			        link.l1.go = "begin_35";
                               
                        break;

                       case "begin_35":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[69];
			        link.l1 = DLG_TEXT[70];
			        link.l1.go = "begin_36";
                               
                        break;

                       case "begin_36":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[71];
			        link.l1 = DLG_TEXT[72];
			        link.l1.go = "begin_37";
                               
                        break;

                       case "begin_37":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[73];
			        link.l1 = DLG_TEXT[74];
			        link.l1.go = "exit";
                              AddDialogExitQuest("inside_fort4");		                               
                        break;

                       case "begin_38":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[75];
			        link.l1 = DLG_TEXT[76];
			        link.l1.go = "exit";
                              AddDialogExitQuest("inside_fort10");		                               
                        break;

                       case "begin_39":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[77];
			        link.l1 = DLG_TEXT[78];
			        link.l1.go = "exit";
                              AddDialogExitQuest("inside_fort14");		                               
                        break;

                       case "begin_40":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[53];
			        link.l1 = DLG_TEXT[79];
			        link.l1.go = "exit";
                              AddDialogExitQuest("outside_fort3");		                               
                        break;

                       case "begin_41":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[80];
			        link.l1 = DLG_TEXT[81];
			        link.l1.go = "begin_42";                               
                        break;

                       case "begin_42":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[82];
			        link.l1 = DLG_TEXT[0];
			        link.l1.go = "exit";
                              AddDialogExitQuest("outside_fort5");	                               
                        break;

                       case "begin_43":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[83];
			        link.l1 = DLG_TEXT[84];
			        link.l1.go = "exit";
                             AddDialogExitQuest("outside_fort15");					
                        break;

                       case "begin_44":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[85];
			        link.l1 = DLG_TEXT[86];
			        link.l1.go = "begin_45";		                               
                        break;

                       case "begin_45":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[87];
			        link.l1 = DLG_TEXT[88];
			        link.l1.go = "begin_46";
                    PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");					
                        break;

                       case "begin_46":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[89];
			        link.l1 = DLG_TEXT[90];
			        link.l1.go = "begin_47";
        			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");					
                        break;

                       case "begin_47":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[91];
			        link.l1 = DLG_TEXT[92];
			        link.l1.go = "begin_48";	                               
                        break;

                       case "begin_48":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[93];
			        link.l1 = DLG_TEXT[94];
			        link.l1.go = "exit";
                              AddDialogExitQuest("outside_fort19");		                               
                        break;

                       case "begin_49":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[95];
			        link.l1 = DLG_TEXT[96];
			        link.l1.go = "begin_50";	                               
                        break;

                       case "begin_50":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[97];
			        link.l1 = DLG_TEXT[98];
			        link.l1.go = "begin_51";
                    PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");					
                        break;
						
                       case "begin_51":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[99];
			        link.l1 = DLG_TEXT[0];
			        link.l1.go = "exit";
        			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");						
                              AddDialogExitQuest("outside_fort30");		                               
                        break;
						
                       case "begin_52":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[100];
			        link.l1 = DLG_TEXT[101];
			        link.l1.go = "exit";
                              AddDialogExitQuest("outside_fort33");		                               
                        break;

                       case "begin_53":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[102];
			        link.l1 = DLG_TEXT[103];
			        link.l1.go = "exit";
                              AddDialogExitQuest("outside_fort41");		                               
                        break;

                       case "begin_54":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[104];
			        link.l1 = DLG_TEXT[105];
			        link.l1.go = "exit";
                    PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");						
                              AddDialogExitQuest("outside_fort53");		                               
                        break;

                       case "begin_55":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[106];
			        link.l1 = DLG_TEXT[107];
			        link.l1.go = "begin_56";
                               
                        break;

                       case "begin_56":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[108];
			        link.l1 = DLG_TEXT[109];
			        link.l1.go = "begin_57";
                               
                        break;

                       case "begin_57":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[110];
			        link.l1 = DLG_TEXT[111];
			        link.l1.go = "begin_58";
                               
                        break;
						
                       case "begin_58":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[112];
			        link.l1 = DLG_TEXT[113];
			        link.l1.go = "exit";
                              AddDialogExitQuest("outside_fort59");		                               
                        break;

                       case "begin_59":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[114];
			        link.l1 = DLG_TEXT[115];
			        link.l1.go = "exit";
                              AddDialogExitQuest("back_grenade5");		                               
                        break;

                       case "begin_60":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[116];
			        link.l1 = DLG_TEXT[117];
			        link.l1.go = "begin_61";
                               
                        break;

                       case "begin_61":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[118];
			        link.l1 = DLG_TEXT[119];
			        link.l1.go = "begin_62";
                               
                        break;

                       case "begin_62":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[120];
			        link.l1 = DLG_TEXT[121];
			        link.l1.go = "begin_63";
                               
                        break;
						
                       case "begin_63":
    
                                dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[122];
			        link.l1 = DLG_TEXT[123];
			        link.l1.go = "exit";
                              AddDialogExitQuest("back_grenade14");		                               
                        break;						
						
                       case "Exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		
                 break;

	}
}
