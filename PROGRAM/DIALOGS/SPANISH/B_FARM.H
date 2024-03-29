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
#include "DIALOGS\SPANISH\B_resident_text.h"

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

	string interiorstr = "mobiliario sencillo";
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
	if(NPChar.chr_ai.group==LAI_GROUP_PLAYER ) adress = " Se�or�a";
	else
	{
		if(PChar.sex=="woman") adress = " mi se�ora";
		else adress = " se�or";
	}

	PlayStereoSound("ambient\town\dog1.wav");
	PlayStereoSound("ambient\town\owen.wav");
	
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

			if(rand(100)<15) // chance for random attack, decrease last figure for fewer attacks
			{
				ChangeCharacterReputation(Pchar, -2);  // punishment: reputationloss. Will be offset if accept the fight	
        		PlayStereoSound("voice\ENGLISH\Eng_m_a_070.wav");	
				Dialog.text =  LinkRandPhrase("�Gracias a Dios que has venido! Puedes defendernos de estos brutos...", "Ah, tu llegada es un regalo del cielo en un momento crucial: est�n a punto de atacarnos. �AY�DANOS!", "Qu� alegr�a verte, necesitamos desesperadamente a alguien como t�, la clase de " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)) + " capaz de luchar para protegernos del ataque...");
				link.l1 = "�Eh, c�lmate! Vaya, pero si est�s temblando de miedo... Ahora, dime lo que est� pasando.";
				if(rand(100)>50) {Link.l1.go = "attack1";}
				else{Link.l1.go = "attack2";}

				link.l9 = "Oh, vamos, �no eres capaz de defenderte por tu cuenta? �Tengo asuntos importantes que atender y no puedo distraerme con peleas de granjeros!";
				link.l9.go = "exit";
			}
			else
			{	
				Dialog.text =  LinkRandPhrase("Ah, nuesro querido patr�n visita su granja. �Qu� puedo hacer por ti," + adress + "?" , "Te doy la bienvenida a mi... esto... tu granja," + adress + ", �qu� deseas?" , "Te doy la bienvenida," + adress + ". �Qu� te trae a mi... esto... tu granja?");
				if(CheckAttribute(pchar,"chr_ai.poison") && pchar.chr_ai.poison > 0)
				{
					Link.l1 = "�Oh, me encuentro fatal! Fiebre, extremidades inflamadass, oscurecimiento alrededor de las heridas... �Me temo que tengo gangrena!";
					Link.l1.go = "infected";
				}
				Link.l2 = B_TEXT[8];
				Link.l2.go = "heal";

				Link.l4 = LinkRandPhrase(B_TEXT[9], B_TEXT[10], B_TEXT[11]);
				Link.l4.go = "chat";

				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER) // if you are the landlord
				{
					if(taxdays>0)
					{
						link.l5 = "�C�mo va la cosecha en mi granja? �Cu�nto hab�is recogido en los " + taxdays + " d�as que han pasado desde mi �ltima visita?";
						if(rand(100)*sti(pchar.reputation)/50 > 20)   // chance for a refusal of payments, decrease last figure for fewer refusals
						{
							Link.l5.go = "tax";
						}
						else
						{
							Link.l5.go = "taxevasion";
						}
					}

					link.l6 = "Hum, me pregunto si esta granja puede mejorarse m�s.";
					link.l6.go = "interior";

					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
						link.l7 = "Escucha: hay mucho canalla suelto que acecha por estas islas, saqueadores que disfrutan robando, torturando y violando. Quiz�s vengan aqu�, y en ese caso, necesitar�s algo que puedas usar como �ltimo recurso. Ten, toma esta granada...";
						link.l7.go = "grenade";
					}

					link.l8 = "Esta granja ya no tiene ninguna utilidad para m�. Desmanteladla, cargad las tablas en la bodega y presentaos al contramaestre para que os asigne vuestros deberes a bordo.";
					link.l8.go = "dismantle";

				}
				else   // if you are NOT the landlord
				{
					link.l9 = "Solo pasaba por aqu�...";
					link.l9.go = "exit";
				}

				Link.l10 = B_TEXT[12];
				Link.l10.go = "exit";

				link.l11 = "Eh, �qu� haces ah� sin moverte? " + LinkRandPhrase("�Te has tragado un palo de escoba?...", "Vamos, rel�jate un poco...", "Espero un poco m�s de actividad en mis arrendatarios, �me oyes?");
				link.l11.go = "motion";

				link.l12 = "Hum, perdona, no quiero ser tiquismiquis, pero este 'edificio' me parece un poco raro...";
				link.l12.go = "odd";

				link.l13 = "�Eh, t�, enfrente del teclado! Este es un edificio creado POR TI, as� que, �por qu� no creas tu propio di�logo para acompa�arlo? Solo tienes que usar Bloc de Notas para abrir el archivo PROGRAM\DIALOGS\SPANISH\" + NPchar.dialog.filename + " y sobreescribir este texto con el tuyo. Luego sigue las instrucciones en los comentarios.";
				link.l13.go = "your_dialog"; //this is the case that runs if you choose the dialogoption l13. It is right below.
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
			Dialog.text = "... y si esa escoria se atreve a entrar en mi... tu propiedad, patr�n, lo volar� por los aires." ;
			link.l1 = "�Esa es la actitud! Me alegra tener s�bditos tan leales. Pero ten cuidado con a qui�n vuelas por los aires...";
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "pistolgrenade" );
			GiveItem2Character(NPchar, "pistolgrenade");
		break;

// add interior
		case "interior":
			Dialog.text = "Oh, s�, podemos deshacernos del "+interiorstr+" que tenemos actualmente si quieres darle a esta granja una nueva funci�n. Solo necesitar� una parte de tus "+ GetSquadronGoods(pchar,GOOD_PLANKS) +" tablas, "+ pchar.money +" piezas de oro y "+ Pchar.Ship.crew.quantity +" marineros. �En qu� est�s pensando?";
			Link.l1 = "Hum, no creo que deba invertir todav�a m�s dinero aqu�.";
			Link.l1.go = "exit";
			Link.l5 = "Mobiliario lujoso (mejora la posibilidad de �xito en el tratamiento de heridas en casas; 5 tablas, 1000 piezas de oro, 1 marinero)";
			Link.l5.go = "luxurious furniture";
		break;

		case "luxurious furniture":
			npchar.interior = "mobiliario lujoso";
			Dialog.text = "�Has dicho " + npchar.interior + "?";
			Link.l2 = "Correcto. Mi secretario te asignar� los recursos necesarios, y espero que el trabajo est� terminado para mi pr�xima visita. �Hasta entonces!";
			Link.l2.go = "erect";
		break;

		case "erect":
			aref interiornewref;
			Items_FindItem(npchar.interior,&interiornewref);
			planks = sti(interiornewref.building.planks);
			money = sti(interiornewref.building.money);
			crew = sti(interiornewref.building.crew);

			if(money > sti(pchar.money) || crew > sti(Pchar.Ship.crew.quantity) || planks > GetSquadronGoods(pchar,GOOD_PLANKS) )
			{
				Dialog.text = "Hum, " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + ", un " + npchar.interior + " requiere " + planks + " tablas, " + money + " piezas de oro y "+crew+" hombres. Pero, como te dec�a, solo tenemos "+ GetSquadronGoods(pchar,GOOD_PLANKS) +" tablas, "+pchar.money+" piezas de oro y "+Pchar.Ship.crew.quantity+" hombres...";
				Link.l3 = "Ups... un peque�o error de c�lculo. Bueno, pues este sitio tendr� que seguir como hasta ahora...";
				Link.l3.go = "exit";
			}
			else
			{
				DialogExit();
				NextDiag.CurrentNode = NextDiag.TempNode;

				// take buildingresources
				RemoveCharacterGoods(pchar, GOOD_PLANKS, planks-1 );
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(Pchar, -money);
				Pchar.Ship.crew.quantity = sti(Pchar.Ship.crew.quantity) -crew;
				
				// store new interior
				lcn.building.(nr).interior = npchar.interior;
			}
		break;


// random attacks
		case "attack1":
			Dialog.text = "Los esclavos de la plantaci�n se han rebelado. '�Y ya se han hecho con algunas armas! �Han sido tratados con tanta brutalidad durante tantos a�os que no perdonar�n la vida a ning�n hombre blanco... o mujer!  Oh, si tan solo tuvi�ramos bastiones, empalizadas, minas y ca�ones...";
			link.l1 = RandSwear() + "�Estos marineros de agua dulce est�n paralizados de miedo! La vida en tierra los ha ablandado. Parece que tendr� que luchar sin su ayuda.";
			link.l1.go = "exit_attack1";
		break;

		case "attack2":
			Dialog.text = "Una banda de bucaneros merodeadores... ��ALL�!!";
			link.l1.go = "exit_attack2";
		break;

		case "Exit_attack1":
		// PB: To prevent the fight from starting before the dialog is closed
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking
			Ambush("rabBlack_1", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_attack2":
		// PB: To prevent the fight from starting before the dialog is closed
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking
			Ambush("Sailors",  3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

// taxes and other profits and rewards
		case "tax":
			npchar.tax = taxdays * 2;	// Reward taxmoney, you can change the figure before the ';' to your liking
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// Reputationinfluence on tax, delete line to disable that 

			Dialog.text = "Hemos logrado cosechar " + npchar.tax + " fanegas de trigo y "  + npchar.tax + " fardos de tabaco. Su exportaci�n nos reporta el dinero que necesitamos urgentemente para comprar las herramientas y suministros que no podemos producir nosotros mismos. Aunque la tienda local no compra el tabaco porque aqu� las plantaciones lo producen en mucha abundancia." ;
			link.l1 = "Estupendo, necesito trigo par aalimentar a mi tripulaci�n hmabrienta. ";
			link.l1.go = "wheat";
			link.l2 = "Me llevar� el tabaco.";
			link.l2.go = "tobacco";
			link.l3 = "�Por qu� " + npchar.tax + " fanegas? �C�mo salen estas cuentas? �Puedes explic�rmelo, por favor?";
			link.l3.go = "economy";
		break;

		case "wheat":
			npchar.taxcrop = GOOD_WHEAT;
			Dialog.text = "�Qu�? �Alimentar a tu tripulaci�n? �Con nuestro trigo?";
			link.l1 = "�Eh, no seas insolente, siervo! Esta es mi granja y por lo tanto mi cosecha.";
			link.l1.go = "tax2";
		break;

		case "tobacco":
			npchar.taxcrop = GOOD_TOBACCO;
			Dialog.text = "�Oh, no! �Quieres llevarte nuestro tabaco?";
			link.l1 = "�Eh, no seas insolente, siervo! Esta es mi granja y por lo tanto mi cosecha.";
			link.l1.go = "tax2";
		break;


		case "tax2":
			Dialog.text = RandSwear() + " Lo siento," + adress + ", ya hemos hecho otros planes para la cosecha. Hemos cortado " + npchar.tax + " unidades �ltimamente y ya hemos contactado con un mercader que se ocupar� de exportarla. Como he dicho, necesitamos urgentemente esos ingresos para comprar lo que no podemos producir por nuestra cuenta.";
			link.l1 = LinkRandPhrase("Esta granja me pertenece, y por lo tanto la madera que produce tambi�n. �Los trabajadores en servidumbre como vosotros no tienen derechos, solo deberes! ","�Para qu� necesit�is dinero y suministros? �Y herramientas? �Acaso no ten�is manos? Despu�s de todo, yo te proporciono todo lo que puedas necesitar: protecci�n, materiales, trabajo...","Yo me embolsar� es... quiero decir, yo me encargar� de eso. Apuesto a que ese comprador te estafar�a, as� que es mejor que yo me encargue personalmente de la venta.") +" Mandadlo todo a mi barco.";
			link.l1.go = "taxfull";
			link.l2 = LinkRandPhrase("Buen trabajo. Te dejar� la mitad de la producci�n a ti. �sala sabiamente para acrecentar tu fortuna (y la mia tambi�n).","Entonces, has trabajado duro, �eh? Como recompensa por tus desvelos, te dejar� la mitad de la producci�n para ti (con la esperanza de que eso te anime a trabajar a�n m�s duro).","Escucha, te dejar� la mitad de este dinero para que puedas mejorar tus condiciones de vida y trabajo. Quiero que mi propiedad sea un lugar feliz y decente (y eficiente y rentable).");
			link.l2.go = "taxhalf";
			link.l4 = "�Tanto? Hum, tendr� que comprobar si queda suficiente espacio en la bodega para todo eso. Ser�a un poco frustrante si los frutos de todo este trabajo tuvieran que acabar abandonados en la playa por falta de capacidad de almacenaje, �eh?";
			link.l4.go = "exit";
			link.l3 = "�Por qu� " + npchar.tax + "? �C�mo salen estas cuentas? �Puedes explic�rmelo, por favor?";
			link.l3.go = "economy";
		break;

		case "taxevasion":
			ChangeCharacterReputation(Pchar, -1);  // punishment: reputationdrop. Change figure to your liking

			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			npchar.tax = taxdays * 10;	// Reward taxmoney, you can change the figure before the ';' to your liking
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// Reputationinfluence on tax, delete line to disable that 

			Dialog.text = RandSwear() + LinkRandPhrase("Oh, mis disculpas, Excelencia, pero hemos pasado por tiempos duros �ltimamente: la fiebre amarilla nos he debilitado y no hemos podido trabajar...", "Lo siento mucho, Se�or�a, pero no me queda ni una fanega en el granero: justo la otra noche, un ladr�n rob� todo lo que ten�a almacenado para ti. Deber�as hacer algo m�s por la seguridad de tus propiedades...", "Odio tener que dec�rtelo, Excelencia, pero apenas sacamos suficiente para vivir en esta propiedad tuya: el suelo es pobre, el clima es malo y la �ltima sequ�a ha echado a perder toda la cosecha...") ;
			link.l1 = LinkRandPhrase("Bueno, si las cosas est�n tan dif�ciles para vosotros, no voy a complic�roslas m�s: os librar�is por esta vez, pero solo esta vez. Porque no puedo permitirme mostrar debilidad demasiado a menudo, solo puedo mantener a mi tripulaci�on bajo control si me muestro inflexible.", "Est� bien, aceptar� tu explicaci�n esta vez. Pero, para la pr�xima, no quiero o�r m�s excusas... Despu�s de todo, se supone que el dinero de vuestras rentas es para financiar mi barco, y a la tripulaci�n no le har� gracia tener que renunciar a sus dividendos.", "Hum, no tiene sentido matar a la vaca que quieres orde�ar, �verdad? No tomar� medidas esta vez, pero espero que reanudes la producci�n en cuanto se apsoible. Aunque mi tripulaci�n se quejar� de que soy demasiado indulgente con vosotros.") + "";
			link.l1.go = "moraledrop";

			link.l2 = LinkRandPhrase("Ya basta de lloriqueos, he o�do esas excusas vac�as demasiadas veces como para darles m�s cr�dito. Seguro que te has pasado los d�as durmiendo en un mont�n de heno en vez de labrar mis campos, �eh? Bueno, si no puedes pagar tus rentas en especie, tendr�s que pagarlas en oro...", "�Maldito vago, deber�as pasar menos tiempo fornicando con tus ovejas! Bueno, si no puedes pagar tus rentas en especie, tendr�s que pagarlas en oro...", "�Calla, embaucador! Probablemente has vendido la producci�na por tu propia cuenta, �eh? Conmigo eso no funcionar�, confiscar� tu dinero. Es m�o, de todas formas.");
			switch(Rand(5))   // chance for taxevader backing down, increase figure for less revolts and suicides
			{
			case 1: link.l2.go = "taxsuicide"; break;
			case 2: link.l2.go = "taxrevolt"; break;
			link.l2.go = "taxfine"; break;
			}
		break;

		case "taxhalf":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			AddCharacterGoods(pchar, sti(npchar.taxcrop), sti(npchar.tax)/2);
			ChangeCharacterReputation(Pchar, 1);  // reward: reputation. Change figure to your liking
			Dialog.text = "Es muy generoso por tu parte, " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + ". �Le dir� a todo el mundo que eres un patr�n amable y que se preocupa por sus inquilinos, te lo aseguro!";
			link.l1 = "Oh, no te molestes, no me importa tanto mi reputaci�n. Por cierto, te concedo la noche libre. �Por qu� no vas a la ciudad, confraternizas con los vecinos, hablas con ellos...? �Divi�rtete!";
			link.l1.go = "exit";
		break;

		case "taxfull":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			AddCharacterGoods(pchar, sti(npchar.taxcrop), sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // punishment: reputationdrop. Change figure to your liking
			Dialog.text =  RandSwear() + LinkRandPhrase("Est� bien, es tu propiedad. Pero no te quejes si te encuentras pronto sin campesinos porque se han muerto de hambre...", "Es poco acertado exprimir una propiedad solo para incrementar el beneficio a corto plazo, si quieres mi opini�n. Pero supongo que no me la has pedido, �eh? Bueno, obtendr�s tu rentabilidad, as� te atragante scon ella...", "�Quieres esquilmar todo el resultado de nuestro duro trabajo? Bueno, pues d�selo a mis... tus campesinos. Y no te sorprendas si parte de la cosecha se cae accidentalmente al mar en el camino a tu barco.") ;
			link.l1 = "Hum, me pregunto si ha sido buena idea manchar mi buena reputaci�n y arruinar la moral de mis campesinos llev�ndome todo el fruto de su trabajo. ";
			link.l1.go = "exit";
		break;

		case "taxrevolt":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(Pchar, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // punishment: reputationdrop. Change figure to your liking
			Ambush("outlaws", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			Dialog.text =  RandSwear() + "Est� bien, toma tus sucias rentas, cerdo capitalista explotador. �Pero no dudes de que los vengadores enmascarados de la OLP te pondr�n ante un tribunal revolucionario por tus actos! �Campesinos del archipi�lago, un�os! �Abajo con el yugo del feudalismo!";
			link.l1 = LinkRandPhrase("No entiendo qu� est�s diciendo, pero si pagas, me da igual.","�Qu�? �La Organizaci�n por la Liberaci�n de los Piratas sigue existiendo? �No hab�a asegurado nuestro gobierno que la 'liberaci�n' de los estados de Berber�a los exterminar�a? Bueno, para que te creas lo que dicen los pol�ticos...","�AARGH! �La Organizaci�n por la Liberaci�n de los Piratas! �Una insurgencia armada en mi propiedad!");
			link.l1.go = "exit";
		break;

		case "taxsuicide":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			Dialog.text =  RandSwear() + LinkRandPhrase("�Si t� me arrebatas mis posesiones, yo te arrebatar� las tuyas! �Con una de tus propias granadas! Ir�nico, �verdad? Mi vida no es m�s que una farsa...","�Eres mi ruina! �C�mo voy a seguir viviendo? �Morir� de hambre!... �NO! �No lo har�! �Prefiero morir r�pido, arder como una estrella y no consumirme como una vela! �D�nde est� mi barril de p�lvora?","�Has destruido mi vida, chupasangre! Lo �nico que me queda es este barril de ron... Delicioso ron, del fuerte, del que quema la garganta como los fuegos del infienro... Los fuegos del infierno, eso es lo que te espera... �ME OYES, CHUPASANGRE? �YO TE ENSE�AR� LOS FUEGOS DEL INFIERNO! Este alcohol no solo quema en la garganta...");
			link.l1 = LinkRandPhrase("Oh, vamos, no seas tan dram�tico...","�Eh!, �qu� est�s tramando? Cuidado, podr�as causar un accidente...","Est� bien, m�tate si te apetece. Los perdedores como t� son f�ciles de reemplazar...");
			link.l1.go = "taxsuicide2";
		break;

		case "taxsuicide2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			Explosion (NPchar, 30);
			Lai_KillCharacter(NPchar);
		break;

		case "taxfine":
			AddMoneytoCharacter(Pchar, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // punishment: reputationdrop. Change figure to your liking
			Dialog.text =  RandSwear() + LinkRandPhrase("Est� bien, toma tu maldito dinero. Pero no te quejes si te encuentras pronto sin trabjadores porque se han muerto de hambre...", "Entonces, no tendr� otra opci�n que pedir prestado el dinero que t edebo aun usurero. Lo que significa que probablemente acabar� con un brazo roto..., en el mejor de los casos...", "Est� bien, sanguijuela, toma. Toma este dinero que hab�a ahorrado para ayudar a mi madre enferma.") ;
			link.l1 = "Hum, me pregunto si ha sido buena idea manchar mi buena reputaci�n isistiendo en el cobro de estas " + tax + " piezas de oro. ";
			link.l1.go = "exit";
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
			Dialog.text = "Ah, a m� me lo dices... �Yo soy quien tiene que soportar la 'rareza' de mi hogar d�a s� y d�a tambi�n! Lo peor es que las paredes est�n tan agrietadas que la gente puede colarse por ellas. No darned privacy, not even in my own bed! Todo es culpa del desgraciado arquitecto que dise�� esto, Couchcaptain Charles. Ese empoll�n picac�digo no tiene ni la menor idea sobre modelos de edificios, solo ha robado dise�os de Inez Diaz y los ha plantado en los lugares m�s imposibles." ;
			link.l1 = "�Eh, deja de quejarte! �No es mejor tener una casa rara que no tener casa? �Preferir�as dormir en la playa? Por mi parte, yo pienso disfrutar de las vistas y de las capacodades de mis nuevos edificios en vez de perder el tiempo con comentarios quisiquillosos.";
			link.l1.go = "exit";
			link.l2 = "En vez de quejarte sobre lo que hacen otros, deber�as mover el culo y resolver el problema t� mismo. �Cu�l es la causa exacta de este problema? S� algunas cosas sobre modelos 3D, �quiz�s pueda ayudar?";
			link.l2.go = "odd2";
			link.l3 = "�Qu� importa el aspecto que tenga? Lo que no me gusta es el aspecto econ�mico: la cantidad de productos y beneficios. Y la frecuencia de ataques y eventos, las penalizaciones...";
			link.l3.go = "tweaking";
		break;

		case "odd2":
			Dialog.text = "Cualquier tipo de ayuda ser� muy apreciada. A algunos de estos modelos de edificios les vendr�a bien una remodelaci�n. El prinicpal problema es que estos modelos de edificios no son parte del modelo del mapa, sino objetos ligados a personajes inm�viles, como yo. Por lo tanto, el 'walkpatch' del modelo del mapa -lo que impide a los personajes caminar a trav�s de las paredes- dno cubres estos nuevos edificios. Lo que neceistamos es un 'walkpatch' alrededor de los objetos que componen el edificio. O alrededor del personaje al que el edificio est� ligado. Si conoces una soluci�n a este problema, ponte en contacto con el foro de la comunidad de creadores de mods de PotC en "+PA_INET;
			link.l1 = "Hum, lo pensar�...";
			link.l1.go = "exit";
		break;

		case "tweaking":
			Dialog.text = "Eso tiene f�cil arreglo. Puedes hacer esa clase de cambios a tu gusto editando un archivo de texto. Por ejemplo, aqu� puedes reducir los pagos que recibes por este negocio: abre el archivo 'Pirates of the Caribbean\PROGRAM\DIALOGS\SPANISH\ " + NPchar.dialog.filename + " ' con un editor d etexto como Bloc de Notas. Usa la funci�n de b�squeda y busca la palabra clave 'reward'. Esto te llevar� a una l�nea similar a esta: ' tax = taxdays * 1;	// Reward ...  '. Reemplaza el '1' por '0.5' para reducir lo que te pago a la mitad (no esperar�s que te diga c�mo aumentarlo ;) ). Del mismo modo, puedes modificar otras cosas buscando las palabras clave 'chance' para la proababilidad de activar eventos, o 'punishment' para cosas como la p�rdida de reputaci�n. Los comentarios que hay detr�s de las '//' barras dobles te explicar�n qu� es lo que hace el c�digo que tienen delante. Para desactivar la infleucnai de la reputaci�n sobre los beneficios, busca las l�neas con el comentario '// reputationinfluence..' y b�rralas. Si necesitas m�s informaci�n, ponte en contacto con el foro de la comunidad de creadores de mods de PotC en "+PA_INET;
			link.l1 = "Gracias por las indicaciones. Parece que moddear no es tan dif�cil, �eh? Solo requiere un poco de paciencia y dedicaci�n. Pero si me manejo jugando a este juego, tambi�n deber�a ser capaz de modificarlo un poco.";
			link.l1.go = "exit";
		break;

		case "economy":
			Dialog.text = "Est� bien, aqu� va una peque�a lecci�n sobre la socioeconom�a de tu propiedad: cada d�a, tus trabajadores y arrendatarios trbaajan en tu propiedad, ahorran sus ganancias o acumulan productos. Cu�nto ahorran y cu�nto acunulan depende en gran medida de tu comportamiento: los trbajadores contentos son m�s eficientes, los trabajadores que se sienten seguros ahorran para el futuro, y si tratas a tus trabajadores con decencia y los proteges, estar�n m�s dispuestos a entregarte dinero o productos. En caso contrario, se vuelven vagos, malversan tu dinero o incluso se rebelan. Tu reputaci�n es importante: cuanto mejor se atu reputaci�n, mayores ser�n tus beneficios, y viceversa. Cuanto mejor sea tu comportamiento en tus propiedades, mejor ser� tu reputaci�n. As� que debes aprender a buscar un equilibrio entre tus necesidades inmediatas de dinero y mercanc�as y la prosperidad de tu negocio a largo plazo. Un buen patr�n es estricto cuando debe y generoso cuando puede." ;
			link.l1 = "�A eso lo llamas socioeconom�a? A m� me suena a vud�. �Para qu� necesit�is ahorros? Despu�s de todo, yo os proporciono todo lo que pod�is necesitar: protecci�n, alojamiento, comida, trabajo... As� que lo correcto ser�a que todo vuestro oro acabe en mis cofr... en los cofres comunales. �Eso es lo que yo llamo socioeconom�a, lo aprend� de un tipo muy listo llamado Marx!";
			link.l1.go = "taxfull";
			link.l2 = "Ya veo... Escucha, os dejar� la mitad de vuestros ahorros para que pod�is mejorar vuestras condiciones d evida y trabajo. Quiero que mi propiedad sea un lugar decente y feliz (y eficiente y rentable).";
			link.l2.go = "taxhalf";
			link.l3 = "Todo esto no me gusta. Sacrificar�a este pago a cambio de informaci�n sobre c�mo editar el mod a mi gusto. Todos estos eventos e influencias mutuas no casan con mi forma de jugar.";
			link.l3.go = "tweaking";
		break;

		case "motion":
			Dialog.text = LinkRandPhrase("Oh, me abruma tanto tu presencia que no puedo moverme.", "He estado trabajando todo el d�a, me duelen los huesos y no dejar� que me impidas tomarme un bien merecido descanso.", "�Me creer�as si te dijera que tengo que soportar todo el peso del edificio? Se vendr�a abajo si hago el m�s m�nimo movimiento...");
			link.l1 = "Est� bien, lo comprendo... Adi�s.";
			link.l1.go = "exit";
		break;

// enc_resident stuff: healing, spending time etc. 
		case "chat":
			dialog.text = B_TEXT[17];
			Link.l4 = B_TEXT[12];
			Link.l4.go = "exit";
			Link.l1 = B_TEXT[18];
			Link.l1.go = "chat2";
		break;

		case "chat2":
			dialog.text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) );

			if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 10.0)
			{
				Link.l1 = B_TEXT[22];
				Link.l1.go = "hall_day_wait";
			}
			else
			{
				Link.l1 = B_TEXT[23];
				Link.l1.go = "hall_night_wait";
			}
		break;

		case "heal":
			Dialog.text = B_TEXT[20];
			Link.l1 = B_TEXT[21];
			if (rand(100) + makeint(pchar.skill.Sneak) >= 35 || interiorstr=="luxurious furniture") {Link.l1.go = "exit recovered";}
			else {Link.l1.go = "exit infected";}
			Link.l3 = B_TEXT[24];
			Link.l3.go = "exit";
		break;

		case "infected":
			Dialog.text = LinkRandPhrase(B_TEXT[25], B_TEXT[26], B_TEXT[27]); 
			int winlink = rand(100) 
			if (winlink >= 50) 
			{
				Link.l1 = LinkRandPhrase(B_TEXT[38], B_TEXT[39], B_TEXT[40]);
				Link.l1.go = "exit recovered"
			}
			Link.l2 = LinkRandPhrase(B_TEXT[41], B_TEXT[42], B_TEXT[43]);
			Link.l2.go = "exit infected";
			Link.l3 = LinkRandPhrase(B_TEXT[44], B_TEXT[45], B_TEXT[46]);
			Link.l3.go = "exit infected";
			if (winlink < 50) 
			{
				Link.l4 = LinkRandPhrase(B_TEXT[38], B_TEXT[39], B_TEXT[40]);
				Link.l4.go = "exit recovered"
			}
			Link.l5 = B_TEXT[47];
			Link.l5.go = "exit";
		break;


		case "hall_day_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			TavernWaitDate("wait_day");
			PlaySound("VOICE\ENGLISH\Eng_m_a_013.wav");
			Log_SetStringToLog("Charl�is durante horas y aprendes mucho.");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 50+(sti(PChar.skill.Leadership)*10)+Rand(50) ); }
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Leadership)*10)+Rand(50)); }
		break;

		case "hall_night_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			TavernWaitDate("wait_night");
			PlaySound("VOICE\ENGLISH\Eng_m_a_014.wav");
			Log_SetStringToLog("Charl�is durante horas y aprendes mucho.");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 50+(sti(PChar.skill.Leadership)*10)+Rand(50) ); }
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Leadership)*10)+Rand(50)); }
		break;

		case "exit recovered":
			Dialog.text = B_TEXT[48];
			Link.l1 = LinkRandPhrase(B_TEXT[49], B_TEXT[50], B_TEXT[51]);
			Link.l1.go = "exit recovered2";
		break;

		case "exit recovered2":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			pchar.chr_ai.poison = 0;
			pchar.chr_ai.hp_max = sti(pchar.chr_ai.hp_max) + 1;
			LAi_SetCurHPMax(pchar);
			LAi_Fade("", "");
			WaitDate("", 0,0,1,0,0);
			RecalculateJumpTable();
			PlaySound("AMBIENT\SHOP\sigh2.wav");
			Log_SetStringToLog("Despu�s de 24 horas, vuelves a estar en forma, incluso m�s fuerte que antes.");
			Log_SetStringToLog("+ 1 salud m�xima");
			Log_SetStringToLog("Has aprendido mucho sobre tratamiento de heridas.");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Defence", 50+(sti(PChar.skill.Defence)*10)+Rand(50) + grgbonus ); }
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Defence)*10)+Rand(50) + grgbonus ); }
		break;

		case "exit infected":
			Dialog.text = B_TEXT[48];
			Link.l1 = LinkRandPhrase(B_TEXT[49], B_TEXT[50], B_TEXT[51]);
			Link.l1.go = "exit infected2";
		break;

		case "exit infected2":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			if (makeint(environment.time) < 22.0 && makeint(environment.time) >= 10.0) TavernWaitDate2("wait_day"); // NK to catch if not night
			TavernWaitDate("wait_day"); // NK so there is a fade
			pchar.chr_ai.poison = 20 + rand(50 -sti(PChar.skill.Sneak) -sti(PChar.skill.defence) );
			grgbonus = 200+Rand(200)
			PlaySound("OBJECTS\DUEL\man_hit6.wav");
			Log_SetStringToLog("Despiertas sinti�ndote febril.");
			Log_SetStringToLog("�Tus heridas arden como el fuego!");
		break;

// dialogexits
		case "moraledrop":
			ChangeCharacterReputation(Pchar, 3);  // reward: reputation. Change figure to your liking

			pchar.ship.crew.morale=makeint(stf(pchar.ship.crew.morale) -5 );  // punishment: crew moraledrop. Change figure to your liking
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
