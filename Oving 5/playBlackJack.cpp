#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "playBlackJack.h"

Blackjack::Blackjack() {		//shuffle kortstokken og trekk to kort til spiller og to kort til dealer (spiller og dealer er variabler)
	
	Kortstokk.shuffle();		//shuffler kortstokken
}

int val(Rank r)				//Prøvde først å endre verdien i enum-klassene s.a alle bildekortene hadde verdi 10, da fikk jeg debug-error fordi c++ da leser alle elementene med lik verdi som samme element
{							//lager heller en funksjon som tar en rank og caster den til en int
	int val = static_cast<int> (r);
	if (val == 14) {
		return 11;
	}
	if (val > 10 && val != 14) {
		return 10;
	}
	return val;
}

void Blackjack::playBlackjack() {
	//UTDELER KORT TIL SPILLER
	//Kort_1
	Card utdelt_kort_spiller{};
	utdelt_kort_spiller = Kortstokk.drawCard(); //trekker nytt kort til bruker
	cout << "Ditt første kort ble: " << utdelt_kort_spiller.toString() << endl;
	int spiller = val (utdelt_kort_spiller.rank());		//konverter spillers kort til int verdi slik at vi kan summere og sammenligne etc. //HJELP
	
	//Kort_2
	Card utdelt_kort{};
	utdelt_kort_spiller = Kortstokk.drawCard();
	cout << "Ditt andre kort ble: " << utdelt_kort_spiller.toString() << endl;
	spiller += val (utdelt_kort_spiller.rank());
	cout << "Summen av dine to kort ble: " << spiller << endl;

	//UTDELT KORT TIL DEALER
	//Kort_1
	Card dKort = Kortstokk.drawCard();
	cout << "Dealer sitt første kort ble: " << dKort.toString() << endl;
	int dealer = val (dKort.rank());

	//KORT_2
	dKort = Kortstokk.drawCard();
	cout << "Dealer sitt andre kort ble: " << dKort.toString() << endl;
	dealer += val (dKort.rank());
	cout << "Summen av dealer sine kort ble: " << dealer << endl;
	cout << "" << endl;
	cout << "" << endl;

	//SPØR SPILLER OM DE VIL TREKKE ETT KORT TIL ELLER BEHOLDE NÅVÆRENDE SUM
	cout << "Ønsker du å trekke et kort til? [J]/[N]" << endl;
	char svar;
	cin >> svar;
	bool tap = false;

	while (toupper(svar) == 'J') {									//Spiller svarer ja på å trekke et kort til
		utdelt_kort_spiller = Kortstokk.drawCard();
		spiller += val(utdelt_kort_spiller.rank());
		cout << "Ditt siste kort ble: " << utdelt_kort_spiller.toString() << endl;
		
		if (dealer < 17) {									//Dersom dealer sin sum er under 17 må dealer trekke et kort til
			dKort = Kortstokk.drawCard();
			dealer += val(dKort.rank());					//dealer sin nye sum
		}
		cout << "Din nye sum ble: " << spiller << endl;
		cout << "Dealer sitt siste kort ble: " << dKort.toString() << endl;
		cout << "Dealer sin sum ble: " << dealer << endl;
		cout << endl;

		if (spiller > 21 || dealer > spiller || (dealer == 21 && spiller != 21)) {
			cout << "Du tapte." << endl;
			tap = true;
			break;
		}

	}
	if (!tap) {
		dealer += val(dKort.rank());
		if ((spiller > dealer && spiller <= 21) || (dealer > 21 && spiller <= 21) || (spiller == 21 && dealer != 21) || ((spiller < dealer) && (dealer > 21) && (spiller <= 21))) { //betingelsene for å ha vunnet
			cout << "Gratulerer, du vant Blackjack! " << endl;
		}
		if (dealer == spiller) {
			cout << "Det ble uavgjort! " << endl;
		}
	}
}
//spør om spilleren vil trekke et kort til(if ja-->trekk, else nei-->gå videre)

/*Handlingsforløp + Blackjack regler
- Shuffle kort
- Dealer kort
- Viser kort
- Dele ut kort
	- et til spiller
	- et til dealer
	- et til spiller
	- et til dealer
- spør om spiller vil ha flere kort
- spiller summerer kortene sin, sum lagres i variabel
- if sum > 21 = du tapte
- if ace + bildekort = ekte blackjack
- if (ekte blackjack) = du vant!
- if (sum = 21 && dealersum != 21) = du vant!
- if (dinsum > dealersum  && dinsum < 21) = du vant!
- if (dinsum < 21 && dealersum > 21) = du vant!
*/