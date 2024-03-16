//#include "DIALOGS\Captaine Chevalle_dialog.h"

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
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			
			if (!CheckAttribute(PChar,"quest.Chevalle"))
			{
				dialog.snd = "Voice\CLLA\CLLA001";
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "begin";
			}

			if (CheckQuestAttribute("Jackpot", "search"))
			{
				dialog.snd = "Voice\CLLA\CLLA004";
				dialog.text = DLG_TEXT[129];
				link.l1 = DLG_TEXT[130];
				link.l1.go = "begin2_3";
			}
		break;

		case "begin2_1":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[131];
			link.l1 = DLG_TEXT[132];
			link.l1.go = "exit";
			AddDialogExitQuest("argument3_CC_CEV");
		break;

		case "begin2_2":
			locCameraRight(NPChar); // a simple virtual sailor
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[133];
			link.l1 = DLG_TEXT[134];
			link.l1.go = "exit";
			AddDialogExitQuest("board_spanish_ship_BR");
		break;

		case "begin2_3":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[135];
			link.l1 = DLG_TEXT[136];
			link.l1.go = "exit";
			AddDialogExitQuest("leavetortuga");
		break;

		case "begin2_4":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[137];
			link.l1 = DLG_TEXT[138];
			link.l1.go = "exit";
			AddDialogExitQuest("meetprisoner");
		break;

		case "begin2_5":
			//locCameraRight(NPChar); // a simple virtual sailor
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[139];
			link.l1 = DLG_TEXT[140];
			link.l1.go = "exit";
			//AddDialogExitQuest("seesoldier");
			AddDialogExitQuest("argument1_CC_CEV");
		break;

		case "begin2_6":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[141];
			link.l1 = DLG_TEXT[142];
			link.l1.go = "exit";
			AddDialogExitQuest("leavedevilcreek2");
		break;

		case "begin2_7":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[143];
			link.l1 = DLG_TEXT[144];
			link.l1.go = "exit";
			AddDialogExitQuest("leaveturner2");
		break;

		case "begin2_8":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[145];
			link.l1 = DLG_TEXT[146];
			link.l1.go = "exit";
			AddDialogExitQuest("seesoldier");
		break;

		case "begin":
			dialog.snd = "Voice\CLLA\CLLA003";
			if (IsInServiceOf(PIRATE))
			{
				dialog.text = DLG_TEXT[6];
				link.l1 = DLG_TEXT[7] + GetMyFullName(PChar) + DLG_TEXT[8] + GetMyShipNameShow(PChar) + "'.";
				link.l1.go = "begin_2";
			}
			else
			{
				dialog.text = DLG_TEXT[147];
				link.l1 = DLG_TEXT[148];
				link.l1.go = "Exit";
			}
		break;

		case "begin_2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "begin_3";
		break;

		case "begin_3":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "begin_4";
		break;

		case "begin_4":
			dialog.snd = "Voice\CLLA\CLLA006";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "begin_5";
		break;

		case "begin_5":
			dialog.snd = "Voice\CLLA\CLLA007";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "begin_6";
		break;

		case "begin_6":
			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "begin_7";
			link.l2 = DLG_TEXT[19];
                        link.l2.go = "begin_9";
		break;

		case "begin_7":
			dialog.snd = "Voice\CLLA\CLLA009";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "begin_8";
		break;

		case "begin_8":
			AddQuestRecord("Pirate Lord", 7);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

			AddDialogExitQuest("Chevalle_start_search");
		break;

                case "begin_9":

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

			AddDialogExitQuest("Chevalle_search_refused");

		break;

                       case "in_shore":

			
                        dialog.snd = "Voice\CLLA\CLLA009";
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];
				link.l1.go = "begin_10";
                        break;

                        case "begin_10":

                        NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
                        AddDialogExitQuest("Chevallefollow");
                        
                        break;

                       case "came":


                        dialog.snd = "Voice\CLLA\CLLA009";
				dialog.text = DLG_TEXT[24];
				link.l1 = DLG_TEXT[25];
				link.l1.go = "begin_11";
                        break;

                        case "begin_11":

                        NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
                        AddDialogExitQuest("fight");
	
	

		     break;

                     case "guarda":


                        dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[26];
			        link.l1 = DLG_TEXT[27] + GetMyFullName(PChar) + DLG_TEXT[28];
			        link.l1.go = "begin_12";
                        break;

                        case "begin_12":


                        dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[29];
			        link.l1 = DLG_TEXT[30];
			        link.l1.go = "begin_13";
                        break;


                        case "begin_13":

                       
                        dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[31];
			        link.l1 = DLG_TEXT[32];
			        link.l1.go = "begin_14";
                        break;

                       case "begin_14":

                        
                        dialog.snd = "Voice\CLLA\CLLA009";          
			        dialog.text = DLG_TEXT[33];
			        link.l1 = DLG_TEXT[34];
			        link.l1.go = "begin_15";
                        break;

                       case "begin_15":


                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "begin_16";
                        
                        break;

                        case "begin_16":

                        NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
                        AddDialogExitQuest("fight_2");

                        break;

                        case "savecrew":


                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "begin_17";

                        break;

                        case "begin_17":

                        NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
                        AddDialogExitQuest("goverplace");

                        break;

                        case "before":

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "begin_18";
                        
                        break;

	                case "begin_18":


                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "begin_19";

                        break;

                        case "begin_19":


                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "begin_20";

                        break;
                         
                        case "begin_20":

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "begin_21";
                        
                        break;
 
                        case "begin_21":

                        NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
                        AddDialogExitQuest("commandant");

                        break;

                        case "devil":

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "begin_22";

                      break;

                       case "begin_22":

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "begin_23";

                      break;

                     case "begin_23":
          
                      NextDiag.CurrentNode = NextDiag.TempNode;
		      DialogExit();
                      AddDialogExitQuest("combat");

                     break;

                    

                     case "Chevallepirat":
                        
                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "begin_25";

                       break;
                     
                  case "begin_25":

                       NextDiag.CurrentNode = NextDiag.TempNode;
		       DialogExit();
                       AddDialogExitQuest("Chevallemoi");

                       break;

                  case "outcity":

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "begin_26";

                   break;
  
                   case "begin_26": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "begin_27";

                      

                   break;
     
                    
                    case "begin_27":

                       NextDiag.CurrentNode = NextDiag.TempNode;
		       DialogExit();
                       AddDialogExitQuest("fight_5");

                   break;
              
                      case "avantplage": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "begin_28";   

                   break;

                      case "begin_28":

                       NextDiag.CurrentNode = NextDiag.TempNode;
		       DialogExit();
                       AddDialogExitQuest("evasion_3");

                   break;
     
             case "second": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "begin_29"; 
                   
                   break; 

             case "begin_29": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "begin_30"; 
                   
                   break; 

             case "begin_30": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "begin_31"; 
                   
                   break; 

             case "begin_31":
                     
                      NextDiag.CurrentNode = NextDiag.TempNode;
		      DialogExit();
                      AddDialogExitQuest("embarquer");
       
                    break;

            case "horsjamaica": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "begin_32"; 
                   
                   break; 

            case "begin_32": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "begin_33"; 
                   
                  break;

           case "begin_33":
                     
                      NextDiag.CurrentNode = NextDiag.TempNode;
		      DialogExit();
                      AddDialogExitQuest("directnevis");

                  break;

           case "lafin": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "begin_34"; 
                   
                  break;

           
           case "begin_34": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "begin_35"; 
                   
                  break;

            case "begin_35": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[76];
			link.l1.go = "begin_36"; 
                   
                  break;

            case "begin_36": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "begin_37"; 
                   
                  break;

            case "begin_37": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "begin_38"; 
                   
                  break;

            case "begin_38": 

                     
                      NextDiag.CurrentNode = NextDiag.TempNode;
		      DialogExit();
                      AddDialogExitQuest("dispute_3");
   
                  break;

            case "lafin_2": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "begin_39"; 
                   
                  break;

            case "begin_39": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "begin_40"; 
                        link.l2 = DLG_TEXT[85];
			link.l2.go = "begin_41"; 
                   
                  break;

            case "begin_40": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87];
			link.l1.go = "begin_42"; 
                   
                  break;

            case "begin_41": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[88];
			link.l1 = DLG_TEXT[89];
			link.l1.go = "begin_43"; 
                   
                  break;



           case "begin_42": 

                     
                      NextDiag.CurrentNode = NextDiag.TempNode;
		      DialogExit();
                      AddDialogExitQuest("Chevalleofficer");
   
                  break;
   
           case "begin_43": 

                     
                      NextDiag.CurrentNode = NextDiag.TempNode;
		      DialogExit();
                      AddDialogExitQuest("Chevallebye");
   
                  break;

           case "crewship": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "exit";
              LAi_SetActorType(characterFromID("Captaine Chevalle"));
              LAi_ActorFollowEverywhere(characterFromID("Captaine Chevalle"), "", 60.0);         
                     
                  break;

            case "begin_44": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[90];
			link.l1 = DLG_TEXT[91];
			link.l1.go = "begin_45"; 
                   
                  break;

            case "begin_45": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[92];
			link.l1 = DLG_TEXT[93];
			link.l1.go = "begin_46"; 
                   
                  break;

            case "begin_46": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[94];
			link.l1 = DLG_TEXT[95];
			link.l1.go = "begin_47"; 
                   
                  break;

            case "begin_47": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "begin_48"; 
                   
                  break;



            case "begin_48": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[98];
			link.l1 = DLG_TEXT[99];
			link.l1.go = "begin_49"; 
			link.l2 = DLG_TEXT[100];
			link.l2.go = "begin_50"; 

                   
                  break;

	    case "begin_49":

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

			AddDialogExitQuest("Santiago_start_search");
		break;

            case "begin_50":

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

			AddDialogExitQuest("Santiago_search_refused");

		break;

		case "begin_51": 
			dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[101];
			link.l1 = DLG_TEXT[102];
			link.l1.go = "begin_51_1"; 
		break;

            case "begin_51_1": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[125];
			link.l1 = DLG_TEXT[126];
			link.l1.go = "exit";
                        AddDialogExitQuest("directbrothel"); 
                   
                  break;				  

            case "begin_52": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[103];
			link.l1 = DLG_TEXT[104];
			link.l1.go = "exit"; 
                        LAi_SetPlayerType(pchar); 
                        LAi_SetOfficerType(characterFromID("Captaine Chevalle"));
                   
                  break;

            case "begin_53": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[106];
			link.l1.go = "begin_54"; 
                   
                  break;

            case "begin_54": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[107];
			link.l1 = DLG_TEXT[108];
			link.l1.go = "begin_55"; 
                   
                  break;

            case "begin_55": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[109];
			link.l1 = DLG_TEXT[110];
			link.l1.go = "begin_55_1";
                  break;

            case "begin_55_1": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[128];
			link.l1.go = "exit_gov";
                  break;

            case "exit_gov": 
				LAi_SetPlayerType(pchar); 
				LAi_SetOfficerType(characterFromID("Captaine Chevalle"));
				PChar.quest.santiago = "payergov";
				DialogExit();
				NextDiag.CurrentNode = NextDiag.TempNode;
			break;

            case "begin_56": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			link.l1.go = "exit_txikilibre";
                       
 
                  break;

			case "exit_txikilibre":
				LAi_SetPlayerType(pchar); 
				LAi_SetOfficerType(characterFromID("Captaine Chevalle")); 
				AddDialogExitQuest("Txikilibre_2");
				DialogExit();
				NextDiag.CurrentNode = NextDiag.TempNode;
			break;

            case "begin_57": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];
			link.l1.go = "exit";
                        LAi_SetOfficerType(characterFromID("Captaine Chevalle"));
                        AddDialogExitQuest("newverif");
                        
                  break;

            case "begin_58": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[115];
			link.l1 = DLG_TEXT[116];
			link.l1.go = "exit_Pijuanplantation";
                  break;

			case "exit_Pijuanplantation":
				LAi_SetPlayerType(pchar); 
				LAi_SetOfficerType(characterFromID("Captaine Chevalle")); 
				AddDialogExitQuest("Pijuanplantation");
				DialogExit();
				NextDiag.CurrentNode = NextDiag.TempNode;
			break;

            case "begin_59": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[117];
			link.l1 = DLG_TEXT[118];
			link.l1.go = "begin_60";
           
                  break;

            case "begin_60":

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[119];
			link.l1 = DLG_TEXT[120];
			link.l1.go = "exit";
                        LAi_SetOfficerType(characterFromID("Captaine Chevalle"));
				AddDialogExitQuest("directbarco1");
                  break;

            case "begin_62":

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[121];
			link.l1 = DLG_TEXT[122];
			link.l1.go = "exit";
                        AddDialogExitQuest("directbarco8");
           
                  break;

            case "begin_63": 

                        dialog.snd = "Voice\CLLA\CLLA009";          
			dialog.text = DLG_TEXT[123];
			link.l1 = DLG_TEXT[124];
			link.l1.go = "exit";
                        LAi_SetOfficerType(characterFromID("Captaine Chevalle"));
                        AddDialogExitQuest("directbarco11");
                        
                        
           
                  break;

          
            case "Exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		

                       break;


	}
}
