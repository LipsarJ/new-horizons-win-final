// ccc Buildingset, new file	
/*
ccc Dec06:
Unlike most other files in this folder this one contains not only a textarray but code and English text merged.

The buildingset has recently been messed up by the attempt to localize my original all-English dialogfiles. 
Instead of spending weeks with fixing and testing the new files I restored my original files. 
However, the localization project has changed the structure of PotC for good : 
Upon loading a  "x-dialog.c" codefile the program now automatically includes a  "x-dialog.h" text array file from the dialogs\english subfolder(or from the Russian folder if you use that language). 
There the dialogtext is supposed to be.

However, I prefer to have code AND plain text in one file, for 3 reasons:
-It is much easier to write
-You have much less bugs with not matching texts
-It is much easier to read and understand the file for debuggers and people who would like to change it
The last point is especially important for me cause the Buildingset is supposed to be a tool for people who want to start modding.
That's why I stick to the original "code plus English text" dialogfiles.

As a concession to the localization project I put these files NOT into the \dialogs rootfolder but into the \dialogs\English subfolder.
So if you want to translate this dialog you can simply copy the "code plus English text" into the subfolder for your language and translate the English text there.
That will certainly be less work and trouble than messing up my files again. 
Not mention the work and trouble that the debuging always causes.
*/
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
	ref lcn = &Locations[FindLocation(PChar.location)];

	string nr = NPChar.lastname;

	string buildingstr = NPChar.equip.blade;
	aref buildingref;
	Items_FindItem(buildingstr,&buildingref);

	string interiorstr = "";
	if(CheckAttribute(Npchar,"equip.gun"))
	{
	interiorstr = NPChar.equip.gun;
	aref interiorref;
	Items_FindItem(interiorstr,&interiorref);
	}

	int planks = 0;
	int money = 0;
	int crew = 0;

	int grgbonus = 0;

	int iDYear = sti(lcn.building.(nr).taxyear);
	int iDMonth = sti(lcn.building.(nr).taxMonth);
	int iDDay = sti(lcn.building.(nr).taxDay);
	int taxdays = GetPastTime("day", iDYear, iDMonth, iDDay, 1, GetDataYear(), GetDataMonth(), GetDataDay(), 1);
	int tax = 0;

	string adress;
	if(NPChar.chr_ai.group==LAI_GROUP_PLAYER ){adress = " mi comandante,";}else{adress = "";}

	PlayStereoSound("ambient\jail\chains.wav");
	PlayStereoSound("ambient\cave\drop5.wav");
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\PADI\PADI001";

			if(rand(100)<10) // chance for random attack, decrease last figure for fewer attacks
			{
				PlayStereoSound("voice\Eng_m_a_070.wav");	
				ChangeCharacterReputation(Pchar, -2);  // punishment: reputationloss. Will be offset if accept the fight	
				Dialog.text = adress + LinkRandPhrase(", fuerzas hostiles avistadas. Preparad la defensa.", ", �movimientos enemigos en nustro sector! �Zafarrancho de combate!", "�Movimientos sospechosos en el per�metro, todos a sus puestos!");

				link.l1 = "Un informe detallado, soldado. Ahora.";
				if(rand(100)>50) {Link.l1.go = "attack1";}
				else{Link.l1.go = "attack2";}

				link.l9 = "�D�jame en paz con esas tonter�as, ese es tu trabajo! Para eso os he contratado como carne de ca�... ca�oneros expertos. De todas formas no tengo tiempo: tengo que irme.";
				link.l9.go = "exit";
			}
			else
			{	
				Dialog.text =  "Informo de que la fortaleza est� guarnecida y lista para el combate," + adress + " todo est� tranquilo en este sector.";

				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER)
				{
					link.l1 = "Nos retiramos de esta posici�n. Desmantelad la fortaleza, cargad las tablas en la bodega y presentaos al contramaestre para que os asigne vuestros deberes a bordo.";
					link.l1.go = "dismantle";

					link.l21 = "Necesito un lugar seguro para almacenar algunos de mis tesoros y objetos personales, y esta vieja fortaleza parece un lugar muy seguro. �Puedes poner algunas cosas a buen recaudo aqu�?";
					link.l21.go = "items";
					link.l22 = "Me gustar�a hablar sobre mis posesiones almacenadas con ese tal Guardi�n de la Modorra.";
					link.l22.go = "items";

					if(sti(pchar.money)>5000 && !CheckCharacterItem(NPChar,"cannon") )
					{
					link.l23 = "Me pregunto si tendr�a sentido apostar un ca��n aqu�.";	// ccc feb06
					link.l23.go = "cannon";
					}

					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
					link.l24 = "Soldado, tengo una misi�n especial para ti. Toma esta granada, y si el enemigo nos supera y asalta esta posici�n...";
					link.l24.go = "grenade";
					}
				}
				else
				{
					link.l1 = "Solo pasaba por aqu�... ";
					link.l1.go = "exit";
				}

				Link.l4 = "Muy bien, soldado, contin�a.";
				Link.l4.go = "exit";

				// ccc feb06 link.l6 = "Who the hell designed this maze of masonry? Can't take a step here without smashing my head into some vault or pillar..";
				// ccc feb06 link.l6.go = "odd";

				link.l5 = "Eh, �qu� haces ah� sin moverte? " + LinkRandPhrase("�Te has tragado un palo de escoba?...", "Vamos, rel�jate un poco... �DESCANSE, SOLDADO!", "Espero un poco m�s de actividad por parte de mis infantes de marina, �me oyes?");
				link.l5.go = "motion";

				link.l9 = "�Eh, t�, enfrente del teclado! Este es un edificio creado POR TI, as� que, �por qu� no creas tu propio di�logo para acompa�arlo? Solo tienes que usar Bloc de Notas para abrir el archivo PROGRAM\DIALOGS\SPANISH\" + NPchar.dialog.filename + " y sobreescribir este texto con el tuyo. Luego sigue las instrucciones en los comentarios.";
				link.l9.go = "your_dialog"; //this is the case that runs if you choose the dialogoption l9. It is right below.
			}
		break;
                
		case "your_dialog":
			Dialog.text = "Escribe aqu� el texto de di�logo del NPC." ;

			link.l1 = "Texto de di�logo del jugador: opci�n link.l1, que cierra el di�logo ";
			link.l1.go = "exit";	// link l1 exits the dialog

			link.l2 = "Texto de di�logo del jugador: opci�n link.l2, que conduce a otro intercambio ";
			link.l2.go = "your_dialog2";	// l2 leads to the case your_dialog2
		break;	// end of case "your_dialog"
                
		case "your_dialog2":
			Dialog.text = "Escribe aqu� el texto de di�logo del NPC." ;

			link.l1 = "Texto de di�logo del jugador: opci�n link.l1, que cierra el di�logo";
			link.l1.go = "exit";	// link l1 exits the dialog

			// Here are some codelines that give you money, items, goods or experience. To activate them delete the comment slashes '//' in front of the code. You can change the amounts to your liking.

			// AddMoneyToCharacter(Pchar, 1000);

			// GiveItem2Character(Pchar, "Spyglass3");
			// GiveItem2Character(Pchar, "Jewelry5");
			// GiveItem2Character(Pchar, "Mineral3");
			// TakenItems(Pchar, "potion1", 3);

 			// AddCharacterGoods(pchar, GOOD_SANDAL, 10 );
			// AddCharacterGoods(pchar, GOOD_SILK, 10 );
			// AddCharacterGoods(pchar, GOOD_RUM, 20 );
			// AddCharacterGoods(pchar, GOOD_WHEAT, 20 );

			// AddPartyExp(PChar, 100 );


		break;	// end of case "your_dialog2"

// give grenade to building for selfdefense                
		case "grenade":
			Dialog.text = "..., los volar� en pedazos. �Conozco mi deber, mi comandante!" ;
			link.l1 = "�As� se habla, soldado! Con tu sentido del deber, pronto llegar�s a cabo (... si vives lo sifciente).";
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "pistolgrenade" );
			GiveItem2Character(NPchar, "pistolgrenade");
		break;

// give cannon to building for selfdefense                
		case "cannon":
			Dialog.text = "�Por supuesto, " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + "! Un ca��n aqu�, cubriendo la entrada, podr� volar por los aires a cualquier intruso." ;	// ccc feb06
			link.l1 = "Quiz�s, pero no quiero gastar todav�a m�s dinero aqu�.";	// ccc feb06
			link.l1.go = "exit";

			link.l2 = "Aqu� tienes 5000 piezas de oro. �Puedes... obtener un buen ca��n con ese dinero?";
			link.l2.go = "cannon2";
		break;

		case "cannon2":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, -5000);
			Pchar.Ship.crew.quantity = sti(Pchar.Ship.crew.quantity) -3;
			lcn.building.(nr).interior = "cannon";
			Dialog.text = "S�, " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + ", conozco bastante bien al sargento mayor del arsenal local. Por 5000 piezas de oro, vender�a toda su artiller�a. Solo necesitar� unas pocas horas." ;
			link.l1 = "�As� se habla, soldado! Con tu buen entendimiento de la log�stica, pronto llegar�s a cabo (.. si vives lo suficiente).";
			link.l1.go = "exit";
		break;

// load itemkeeper                
		case "items":
		  if(taxdays>0 && rand(100)<120) // chance for random jewel, increase last figure for	more jewels	  
		  {
  	 		lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
  			Dialog.text = LinkRandPhrase("Ah, hablando de objetos valiosos, eso me recuerda que encontr� una joya en las viejas catacumbas debajo de la fortaleza. Estaba mean... patrullando ah� abajo cuando descubr� una hendidura en la pared. Conduc�a a una antigua c�mara funeraria y, entre un mont�n de viejos huesos, encontr� esta peque�a gema. La forma en que brillaba era como si me invitar a tomarla. Pero al pensarlo mejor, me di cuenta de que ", "Por cierto, tengo una nueva adici�n para tus posesiones: esta joya. La encontr� ayer despejando escombros de un muro derrumbado. Entre las piedras, hab�a una urna rota, cenizas, astillas de hueso, dientes... Y esta hermosa gema. Por supuesto, ", "Antes de empezar a rebuscar en tu inventario, a�ade esta joya. Ayer estaba despejando la cripta de la antigua capilla de la fortaleza para hacer sitio a mis reservas de ron... munici�n, cuando este objeto brillante se cay� de un mont�n de huesos que estaba transportando. Cay� en mi regazo ocmo un regalo del cielo. O del Hades, quiz�s. Por derecho, ")  + "te pertenece a ti, ya que la propiedad es tuya. As� que prefiero entreg�rtela, no sea que la maldici�n de su due�o muerto caiga sobre m�." ;
  			link.l1 = "(�Maldici�n de su due�o muerto? �Qu� yuyu!) Oh, no, qued�tela. Despu�s de todo, mereces una recompensa por tu honestidad y tu lealtad, soldado. Con tu sentido de la honradez, pronto llegar�s a cabo (.. si vive lo suficiente).";
  			link.l1.go = "reward";
  			link.l2 = "�Mladici�n? �Supersticiones est�pidas! Quieres asustarme para que te deje la gema a t�, �eh? No funcionar�, d�mela. �Es una orden de tu comandante! ";
  			link.l2.go = "jewel";
			}
			else
		  {
  	 		lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
  			Dialog.text = "S�, " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + ", llamar� al Guardi�n de la Mazmorra. Por cierto, puede que su forma de ser sea un poco anticua... tradicional; ha estado viviendo en esta vetusta torre demasiado tiempo, si quieres mi opini�n. Pero esa actitud tradicional es precisamente la que hace de �l un excelente guardi�n de tus tesoros. Puedes darle cualquier cosa para que la ponga a buen recaudo y ten por seguro que te la devolver� cuando la necesites." ;
  			link.l1 = "Eso espero. �D�nde est� ese fact�tum medieval?";
  			link.l1.go = "items2";
			}
		break;

		case "jewel":
		  GiveItem2Character(PChar, "jewelry"+ makeint(1 + rand(15)) );
		  if(rand(100)<20) // chance of poisoning, decrease last figure for	less poisoning	  
		  {
  			DialogExit();
  			NextDiag.CurrentNode = NextDiag.TempNode;
  			pchar.chr_ai.poison = 20 + rand(50 -sti(PChar.skill.Sneak) -sti(PChar.skill.defence) );
  			PlaySound("OBJECTS\DUEL\man_hit6.wav");
  			Logit("�Maldici�n? �La tumba de una v�ctima de peste? �Sea lo que sea, de repente sientes un terrible malestar!");
			}
			else
		  {
  		  pchar.ship.crew.morale=makeint(stf(pchar.ship.crew.morale) -5 );  // punishment: crew moraledrop. Change figure to your liking
  			Dialog.text = "S�, " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + ",tus deseos son �rdenes. Por cierto, �qu� tal una peque�a... recompensa? �No ser�a bueno para la moral de la tropa recompensar a los soldados leales y honrados?" ;
  			link.l1 = "�Bastardo insolente! �Demandas veladas? �C�mo te atreves! Ya basta, quiero ocuparme d emis tesoros. �AHORA!";
  			link.l1.go = "items";
			}
		break;

		case "reward":
			ChangeCharacterReputation(Pchar, 2);  // reward: reputation. Change figure to your liking
			Dialog.text = "Es muy generoso por tu parte, " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + ". �Le dir� a todo el mundo que eres un comandante amable y que se preocupa por sus soldados, te lo aseguro!";
			link.l1 = "Oh, no te molestes, no me importa tanto mi reputaci�n. Por cierto, te concedo un permiso para esta noche. �Por qu� no vas a la ciudad, confraternizas con los vecinos, hablas con ellos...? �Divi�rtete!";
			link.l1.go = "items";
		break;

		case "items2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			ref chr = characterFromID("B_keeper");	
			string locator = LAi_FindRandomLocator("reload");
			float x,y,z;
	  	   	ChangeCharacterAddressGroup(chr, pchar.location, "reload", locator);
  			GetCharacterPos(pchar, &x, &y, &z);
  			x = x+1;
  			TeleportCharacterToPos(chr, x, y, z);
  			Lai_SetActorType(chr);
  			LAi_ActorTurnToCharacter(chr, pchar);
  			LAi_ActorDialog(chr,pchar, "", 4.0, 1.0);
		break;


// random attacks
		case "attack1":
			Dialog.text = "�Se acercan los salvajes can�bales akellani, " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + "! Oh, si tan solo tuvi�ramos m�s bastiones, empalizadas, minas y ca�ones...";
			link.l1 = RandSwear() + " �Atenci�n, soldado! Mant�n esta posici�n pase lo que pase. No dejes de dispararg y no dejes que el enemigo te arrastre a un combate cuerpo a cuerpo. Yo me ocupar� de eso...";
			link.l1.go = "exit_attack1";
		break;

		case "attack2":
			Dialog.text = "�Francisco Pizarro el Joven y su horda de conquistadores merodeadores se acercan, " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + "! �vidos de sangre, bot�n y bajos instintos... Oh, si tan solo tuvi�ramos m�s bastiones, empalizadas, minas y ca�ones...";
			link.l1 = RandSwear() + " �Atenci�n, soldado! Mant�n esta posici�n pase lo que pase. No dejes de dispararg y no dejes que el enemigo te arrastre a un combate cuerpo a cuerpo. Yo me ocupar� de eso...";
			link.l1.go = "exit_attack2";
		break;

		case "Exit_attack1":
		// PB: To prevent the fight from starting before the dialog is closed
			Ambush("native", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_attack2":
		// PB: To prevent the fight from starting before the dialog is closed
			Ambush("Soldier_Spa2",  3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

// dismantling of this building
		case "dismantle":
			DialogExit();
			planks += sti(buildingref.building.planks);
			crew += sti(buildingref.building.crew);

			if(CheckAttribute(Npchar,"equip.gun"))
			{
				planks += sti(interiorref.building.planks);
				crew += sti(interiorref.building.crew);
			}
			AddCharacterGoods(pchar, GOOD_PLANKS, planks);
			AddCharacterCrew(pchar, crew);   // ccc mar06
			Lai_KillCharacter(npchar);
		break;

// info about modding                
		case "odd":
			Dialog.text = "S�, es cierto, el dise�o de esta fortaleza es anticuado. El torre�n pentagonal fue inventado en tiempos de los normandos, cuando las principales amenazas para una fortificaci�n eran las escalas y las m�quinas de asedio simples. Est� pensado para resisitr contra arietes y minas, por lo que los s�tanos y pisos inferiores est�n casi completamente rellenos de sillares y ofrecen poco espacio para el alojamiento. La invenci�n de la p�lvora ha hecho que esta arquitectura se quede obsoleta. Hoy en d�a, estas torres se suelen usar como prisiones o para almacenar tesoros, porque esa era su funci�n original: evitar que la gente entrara. O saliera." ;
			link.l1 = "Hum, en ese caso es un dise�o muy exitoso: encuentro muy dif�cil entrar o salir sin atravesar una pared.";
			link.l1.go = "exit";
		break;

		case "motion":
			Dialog.text = LinkRandPhrase(XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + ", siempre nos ponemos firmes en presencia de un superior. Esa es nuestra ionstrucci�n y la instrucci�n lo es todo.", "Le tengo el ojo echado a un objetivo sospoechoso y no quiero perderlo. 'Apunta bien, no te muevas, no parpadees', sol�a decir nuestro sargento instructor.", "La primera regla del camuflaje: el movimiento atrae la atenci�n. As� que nunca te muevas si no tienes que hacerlo.");
			link.l1 = "Est� bien, entiendo... Contin�a.";
			link.l1.go = "exit";
		break;


// dialogexits

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
