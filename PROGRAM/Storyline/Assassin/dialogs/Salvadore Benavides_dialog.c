//#include "DIALOGS\Salvadore Benavides_dialog.h"
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

			Dialog.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Exit";

		break;
		
                case "begin_1":
  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "begin_2";
               break;


                case "begin_2":
  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];			
			link.l1.go = "begin_3";		
               break;

                case "begin_3":
  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "begin_4";
               break;

                
                case "begin_4":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "begin_5";
                      
                    
		break;

                case "begin_5":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];			
			link.l1.go = "begin_6";		

		break;

                case "begin_6":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "begin_7";
                       
		break;

                case "begin_7":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "begin_8";			
                       
		break;

                case "begin_8":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "begin_9";
                       
		break;

                case "begin_9":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "begin_10";
			
		break;
		
                case "begin_10":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "begin_11";
		                       
		break;
		
                case "begin_11":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "begin_12";
                       
		break;

                case "begin_12":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "begin_13";			
                       
		break;

                case "begin_13":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "begin_14";
                       
		break;

                case "begin_14":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "begin_15";
			
		break;
		
                case "begin_15":
			dialog.snd = "Voice\CLLA\CLLA004";
			if(IsInServiceOf(SPAIN)) {
				dialog.text = DLG_TEXT[30];
			}else{
				dialog.text = DLG_TEXT[246];
				SetRank(PChar, SPAIN, GetOldRank(PChar, SPAIN));
			}
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
                       LAi_QuestDelay("viagem_timer1", 0.0);
                        PlayStereoSound("INTERFACE\took_item.wav");
            			AddMoneyToCharacter(pchar, 2000);					   
                       AddDialogExitQuest("voirdamski");		                       
		break;

                case "begin_16":  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "begin_17";
                                Pchar.quest.viagem_timer1.over = "yes";			
               break;

                case "begin_17": 
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];			
			link.l1.go = "begin_18";
			TakeItemFromCharacter(pchar, "report");			
               break;

                case "begin_18":  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "begin_19";
               break;
              
                case "begin_19":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "begin_20";                                      
		break;

                case "begin_20":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];			
			link.l1.go = "begin_21";		

		break;

                case "begin_21":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "exit";
                       PlayStereoSound("INTERFACE\took_item.wav");
			           AddMoneyToCharacter(pchar, 5000);			
                       AddDialogExitQuest("spyoxbay");	                       
		break;
		
                case "begin_22": 
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "begin_23";
                                Pchar.quest.viagem_timer2.over = "yes";
                                Pchar.quest.maumeet.over = "yes";									
               break;

                case "begin_23": 
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];			
			link.l1.go = "begin_24";
                       PlayStereoSound("INTERFACE\took_item.wav");
			           AddMoneyToCharacter(pchar, 5000);			
               break;

                case "begin_24":  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "begin_25";
               break;
                
                case "begin_25":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "begin_26";                    
		break;

                case "begin_26":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];			
			link.l1.go = "begin_27";
		break;
		
                case "begin_27":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];			
			link.l1.go = "exit";
                       AddDialogExitQuest("spypop");				
		break;
				
                case "begin_28":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];			
			link.l1.go = "begin_29";
		break;
		
                case "begin_29":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];			
			link.l1.go = "begin_30";
                       PlayStereoSound("INTERFACE\took_item.wav");
			           AddMoneyToCharacter(pchar, 5000);
                       Pchar.quest.viagem_timer1.over = "yes";			
		break;

                case "begin_30":  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "begin_31";
               break;

                case "begin_31":  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];			
			link.l1.go = "begin_32";		
               break;

                case "begin_32":  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "begin_33";
               break;
                
                case "begin_33":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "begin_34";                                       
		break;

                case "begin_34":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "exit";
                       AddDialogExitQuest("retourAdmiral");                                       
		break;

                case "begin_35":  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "begin_36";
               break;

                case "begin_36":  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];			
			link.l1.go = "begin_37";
			TakeItemFromCharacter(pchar, "order");					
               break;

                case "begin_37":  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[76];
			link.l1.go = "begin_38";
               break;
                
                case "begin_38":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "begin_39";                                       
        		break;

                case "begin_39":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "begin_40";
                       PlayStereoSound("INTERFACE\took_item.wav");
			           AddMoneyToCharacter(pchar, 15000);                                      
		break;

                case "begin_40":  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "begin_41";
               break;
                
                case "begin_41":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "begin_42";                                       
        		break;

                case "begin_42":  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "begin_43";
               break;
			   
                case "begin_43":  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "begin_44";
               break;
                
                case "begin_44":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "begin_45";                                       
        		break;			   
                
                case "begin_45":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "begin_46";                                       
        		break;

                case "begin_46":  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "exit";
                      AddDialogExitQuest("meet_thug3"); 			
               break;

                case "begin_47":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "begin_48";                                       
        		break;

                case "begin_48":  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "begin_49";
                       PlayStereoSound("INTERFACE\took_item.wav");
			           AddMoneyToCharacter(pchar, 15000);					   
               break;

                case "begin_49":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[100];
			link.l1.go = "begin_50";                                       
        		break;

                case "begin_50":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[101];
			link.l1 = DLG_TEXT[102];
			link.l1.go = "begin_51";                                       
        		break;

                case "begin_51":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[103];
			link.l1 = DLG_TEXT[104];
			link.l1.go = "begin_52";                                       
        		break;

                case "begin_52":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[106];
			link.l1.go = "exit";
                      AddDialogExitQuest("Hit_complete_end2"); 			
        		break;

                case "begin_53":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[107];
			link.l1 = DLG_TEXT[108];
			link.l1.go = "begin_54";                                       
        		break;

                case "begin_54":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[109];
			link.l1 = DLG_TEXT[110];
			link.l1.go = "begin_55";                                       
        		break;

                case "begin_55":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			link.l1.go = "begin_56";                                       
        		break;

                case "begin_56":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];
			link.l1.go = "begin_57"; 			
        		break;

               case "begin_57":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[115];
			link.l1 = DLG_TEXT[116];
			link.l1.go = "begin_58";                                       
        		break;

                case "begin_58":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[117];
			link.l1 = DLG_TEXT[118];
			link.l1.go = "begin_59";                                       
        		break;

                case "begin_59":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[119];
			link.l1 = DLG_TEXT[0];
			link.l1.go = "exit";
                      AddDialogExitQuest("chegabutcher"); 			
        		break;

                case "begin_60":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[120];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
                      AddDialogExitQuest("irplantation"); 			
        		break;

               case "begin_61":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[121];
			link.l1 = DLG_TEXT[122];
			link.l1.go = "begin_62";                                       
        		break;

                case "begin_62":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[123];
			link.l1 = DLG_TEXT[0];
			link.l1.go = "exit";
                        PlayStereoSound("INTERFACE\took_item.wav");
            			AddMoneyToCharacter(pchar, 20000);				
                      AddDialogExitQuest("Governador_forte"); 				
        		break;

                case "begin_63":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[124];
			link.l1 = DLG_TEXT[125];
			link.l1.go = "begin_64";	
        		break;

                case "begin_64":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
                      AddDialogExitQuest("voltarporto"); 				
        		break;

                case "begin_65":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[128];
			link.l1.go = "begin_66";	
        		break;

                case "begin_66":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[129];
			link.l1 = DLG_TEXT[130];
			link.l1.go = "begin_67";	
        		break;

                case "begin_67":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[131];
			link.l1 = DLG_TEXT[132];
			link.l1.go = "begin_68";	
        		break;

                case "begin_68":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[133];
			link.l1 = DLG_TEXT[134];
			link.l1.go = "begin_69";	
        		break;

                case "begin_69":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[135];
			link.l1 = DLG_TEXT[136];
			link.l1.go = "begin_70";	
        		break;

                case "begin_70":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[137];
			link.l1 = DLG_TEXT[138];
			link.l1.go = "begin_71";	
        		break;

                case "begin_71":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[139];
			link.l1 = DLG_TEXT[140];
			link.l1.go = "begin_72";	
        		break;

                case "begin_72":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[141];
			link.l1 = DLG_TEXT[142];
			link.l1.go = "begin_73";	
        		break;

                case "begin_73":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[143];
			link.l1 = DLG_TEXT[144];
			link.l1.go = "exit";
                      AddDialogExitQuest("irAntigua"); 				
        		break;

                case "begin_74":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[145];
			link.l1 = DLG_TEXT[146];
			link.l1.go = "begin_75";	
        		break;

                case "begin_75":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[147];
			link.l1 = DLG_TEXT[148];
			link.l1.go = "begin_76";
                        PlayStereoSound("INTERFACE\took_item.wav");
            			AddMoneyToCharacter(pchar, 25000);				
        		break;

                case "begin_76":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[149];
			link.l1 = DLG_TEXT[150];
			link.l1.go = "begin_77";				
        		break;

                case "begin_77":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[151];
			link.l1 = DLG_TEXT[152];
			link.l1.go = "begin_78";	
        		break;

                case "begin_78":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[153];
			link.l1 = DLG_TEXT[154];
			link.l1.go = "begin_79";		
        		break;

                case "begin_79":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[155];
			link.l1 = DLG_TEXT[156];
			link.l1.go = "begin_80";		
        		break;

                case "begin_80":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[157];
			link.l1 = DLG_TEXT[158];
			link.l1.go = "begin_81";		
        		break;

                case "begin_81":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[159];
			link.l1 = DLG_TEXT[160];
			link.l1.go = "begin_82";		
        		break;

                case "begin_82":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[161];
			link.l1 = DLG_TEXT[162];
			link.l1.go = "begin_83";		
        		break;

                case "begin_83":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[163];
			link.l1 = DLG_TEXT[164];
			link.l1.go = "exit";
                      AddDialogExitQuest("bataille_naval"); 			
        		break;

                case "begin_84":
			if (pchar.ship.type == "FR_Couronne")
			{			
				dialog.snd = "Voice\CLLA\CLLA004";
				dialog.text = DLG_TEXT[165];
				link.l1 = DLG_TEXT[166];
				link.l1.go = "begin_85";
				PlayStereoSound("INTERFACE\took_item.wav");
            			AddMoneyToCharacter(pchar, 30000);
            		}
            		else
            		{
				dialog.snd = "Voice\CLLA\CLLA004";
				if (CheckAttribute(PChar, "quest.no_couronne")) dialog.text = DLG_TEXT[247];
				else
				{
					PChar.quest.no_couronne = true;
					dialog.text = DLG_TEXT[245];
				}
				Link.l1 = DLG_TEXT[29];
				Link.l1.go = "Exit_get_ship";			
			}			
        	break;

                case "begin_85":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[167];
			link.l1 = DLG_TEXT[168];
			link.l1.go = "begin_86";		
        		break;

                case "begin_86":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[169];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
                      AddDialogExitQuest("acaba_mona"); 			
        		break;

                case "begin_87":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[170];
			link.l1 = DLG_TEXT[171];
			link.l1.go = "exit";
                      AddDialogExitQuest("Cuban_villagebis"); 			
        		break;

                case "begin_88":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[172];
			link.l1 = DLG_TEXT[0];
			link.l1.go = "exit";
                      AddDialogExitQuest("Cuban_villagebis3"); 			
        		break;

                case "begin_89":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[173];
			link.l1 = DLG_TEXT[0];
			link.l1.go = "exit";
                      AddDialogExitQuest("see_cuban_governor"); 			
        		break;

               case "begin_90":  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[174];
			link.l1 = DLG_TEXT[175];
			link.l1.go = "begin_91";
               break;

                case "begin_91": 
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[176];
			link.l1 = DLG_TEXT[177];			
			link.l1.go = "begin_92";		
               break;

                case "begin_92": 
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[178];
			link.l1 = DLG_TEXT[179];
			link.l1.go = "begin_93";
               break;
              
                case "begin_93":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[180];
			link.l1 = DLG_TEXT[181];
			link.l1.go = "begin_94";                                    
		break;

                case "begin_94":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[182];
			link.l1 = DLG_TEXT[183];			
			link.l1.go = "begin_95";		
		break;

                case "begin_95":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[184];
			link.l1 = DLG_TEXT[185];
			link.l1.go = "begin_96";                      
		break;

                case "begin_96":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[186];
			link.l1 = DLG_TEXT[187];
			link.l1.go = "begin_97";			                      
		break;

                case "begin_97":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[188];
			link.l1 = DLG_TEXT[189];
			link.l1.go = "exit";
		    GiveItem2Character(Pchar, "purse");			
                      AddDialogExitQuest("going_bonaire");				
		break;				

                case "begin_99":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[56];		
			link.l1.go = "exit";
                       AddDialogExitQuest("final_infeliz");				
		break;

                case "begin_98":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[190];
			link.l1 = DLG_TEXT[191];
			link.l1.go = "begin_100";                      
		break;

                case "begin_100":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[192];
			link.l1 = DLG_TEXT[193];
			link.l1.go = "begin_101";			                      
		break;

                case "begin_101":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[194];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";		
                      AddDialogExitQuest("attendre_info");				
		break;

                case "begin_102":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[195];
			link.l1 = DLG_TEXT[196];
			link.l1.go = "begin_103";                      
		break;

                case "begin_103":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[197];
			link.l1 = DLG_TEXT[198];
			link.l1.go = "begin_104";			                      
		break;

                case "begin_104":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[199];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "exit";
		    GiveItem2Character(Pchar, "purse");				
                      AddDialogExitQuest("fleet_towards_aruba");				
		break;

                case "begin_105":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[200];
			link.l1 = DLG_TEXT[201];
			link.l1.go = "begin_106";                      
		break;

                case "begin_106":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[202];
			link.l1 = DLG_TEXT[203];
			link.l1.go = "begin_107";			                      
		break;

                case "begin_107":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[204];
			link.l1 = DLG_TEXT[205];
			link.l1.go = "begin_108";                      
		break;

                case "begin_108":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[206];
			link.l1 = DLG_TEXT[207];
			link.l1.go = "begin_109";			                      
		break;

                case "begin_109":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[208];
			link.l1 = DLG_TEXT[0];
			link.l1.go = "begin_110";                      
		break;

                case "begin_110":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[209];
			link.l1 = DLG_TEXT[0];
			link.l1.go = "begin_111";			                      
		break;

                case "begin_111":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[210];
			link.l1 = DLG_TEXT[211];
			link.l1.go = "begin_112";                      
		break;

                case "begin_112":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[212];
			link.l1 = DLG_TEXT[213];
			link.l1.go = "begin_113";			                      
		break;

                case "begin_113":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[214];
			link.l1 = DLG_TEXT[215];
			link.l1.go = "begin_114";                      
		break;

                case "begin_114":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[216];
			link.l1 = DLG_TEXT[217];
			link.l1.go = "begin_115";			
		break;

                case "begin_115":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[218];
			link.l1 = DLG_TEXT[219];
			link.l1.go = "begin_116";                      
		break;

                case "begin_116":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[220];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
                    PlayStereoSound("INTERFACE\took_item.wav");
            		AddMoneyToCharacter(pchar, 30000);			
                      AddDialogExitQuest("join_butcher");				
		break;

                case "begin_117":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[221];
			link.l1 = DLG_TEXT[222];
			link.l1.go = "begin_118";			
		break;

                case "begin_118":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[223];
			link.l1 = DLG_TEXT[224];
			link.l1.go = "begin_119";			
		break;

                case "begin_119":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[225];
			link.l1 = DLG_TEXT[226];
			link.l1.go = "begin_120";			
		break;

                case "begin_120":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[227];
			link.l1 = DLG_TEXT[228];
			link.l1.go = "begin_121";			
		break;

                case "begin_121":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[229];
			link.l1 = DLG_TEXT[230];
			link.l1.go = "begin_122";			
		break;

                case "begin_122":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[231];
			link.l1 = DLG_TEXT[232];
			link.l1.go = "begin_123";			
		break;

                case "begin_123":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[233];
			link.l1 = DLG_TEXT[234];
			link.l1.go = "begin_124";			
		break;

                case "begin_124":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[235];
			link.l1 = DLG_TEXT[236];
			link.l1.go = "begin_125";			
		break;

                case "begin_125":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[237];
			link.l1 = DLG_TEXT[238];
			link.l1.go = "begin_126";			
		break;

                case "begin_126":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[239];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
                      AddDialogExitQuest("Governor_Puerto");				
		break;

                case "begin_127":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[240];
			link.l1 = DLG_TEXT[241];
			link.l1.go = "begin_128";			
		break;

                case "begin_128":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[242];
			link.l1 = DLG_TEXT[243];
			link.l1.go = "begin_129";
                    PlayStereoSound("INTERFACE\took_item.wav");
            		AddMoneyToCharacter(pchar, 80000);				
		break;

                case "begin_129":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[244];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";			
                      AddDialogExitQuest("recevoir_recompensebis3");				
		break;				
				
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_get_ship":
			NextDiag.CurrentNode = "begin_84";
			DialogExit();
		break;

	}
}
