========================================================================
    CONSOLE APPLICATION : Conquistadors Project Overview
========================================================================

Klasy:
	-Human
		POLA:
			- int hunger
		METODY:
			Human(int hunger);			-kontruktor
			int getHunger()				-podaje warto�� aktualnego stanu g�odu
			void setHunger(int hunger)	-ustawia nowy stan g�odu
			int random(int a, int b);	-losuje liczbe z przedzia�u a,b

	-Collector, dziedziczy po Human
		POLA:
			int backpackCapacity;	-tyle jedzenia i skarb�w mo�e na raz ud�wign�� collector
			int foundFood = 0;		-jedzenie kt�re znalaz� podczas jednego wyj�cia		
			int foundTreasure = 0;	-skarby kt�re znalaz� podczas jednego wyj��ia
		Metody:
			Collector();	-kontruktor 
			int getBackpackCapacity()	-podaje warto�� aktualnej pojemno�ci plecaka
			int getFoundFood()			-podaje ilo�� znalezionego jedzenia
			int getFoundTreasure()		-podaje ilo�� znalezionych skarb�w
			void setBackpackCapacity(int backpackCapacity)	-ustawia warto�� pojemno�ci 
			void setFoundFood(int foundFood)	-ustawia ilo�� znalezionego jedzenia
			void setFoundTreasure(int foundTreasure) -ustawia ilo�� znalezionych skarb�w
			void foodFound();			-dodaje 5 jednostek jedzenia do znalezionego jedzenia i zmniejsza o 5 pojemno�� plecaka
			void treasureFound();		-dodaje 1 jednostke skarb�w do znalezionych skarb�w i zmniejsza o 1 pojemno�� plecaka
			void clearBackpack();		- zeruje plecak

	-CollectorsTeam, dziedziczy po Collector
		POLA:
			vector<Collector*>collectorsPack;	-zbi�r wszystkich �yj�cych collector�w
		Metody:
			collectorsTeam();
			void collectorsGoOut();		-najpierw sprawdza czy wgl jacy� collectorzy �yj�, losuje ile razy znajd� jedzenie i skarby oraz jak du�o
			int collectorsComeBackWithFood();		-zwraca ilo�� przyniesionego jedzenia (sume p�l foundFood wszystkich collector�w w wektorze)
			int collectorsComeBackWithTreasure();	-j.w. ale skarb�w
			void collectorsWereAttacked();			-losowo collectorzy mog� by� lub nie napadni�ci przez indian, losowa ich liczba wtedy ginie
			int dailyHunger();							-zwraca ilo�� jedzenia kt�re potrzebowa� b�dzie ca�y wektor oraz odejmuje punkty g�odu ka�demu elementowi
			int dailyEating(int needed, int stored);	-daje ka�demu potrzebn� ilo�� jedzenia i odejmuje je od pola storedFood osady
			void isCollectorDead();						-sprawdza poziom g�odu
			void collectorsDie(int d);					-usuwa d element�w z wektora

	-Soldier, dziedziczy po Human
		POLA:
			int combatPoints; -punkty walki, je�eli jaki� �o�nierz stoczy� troche walk to pokona wi�cej indian
		Metody:
			Soldier(int health = 100, int hunger = 100, int combatPoints = 10);	-konstruktor
			int getcombatPoints()	zwraca ilo�� punkt�w
			void setCombatPoints(int combatPoints) ustawia ilo�� punkt�w
			int combatPointsMeaning(int combatPoints); algorytm do przetworzenia punkt�w na wp�yw w walce

	-SoldiersTeam, dziedziczy po Soldier
		POLA:
			vector<Soldier*>soldiersPack;	-zbi�r wszystkich �yj�cych �o�nierzy
		Metody:
			SoldiersTeam();					-konstruktor
			int indiansAttack(int days);	-losuje czy indianie zaatakowali osade oraz ich liczbe na podstawie dnia symulacji
			int battleResult(int x);		-zwraca ilo�� poleg�ych �o�nierzy
			int dailyHunger();							-zwraca ilo�� jedzenia kt�re potrzebowa� b�dzie ca�y wektor oraz odejmuje punkty g�odu ka�demu elementowi
			int dailyEating(int needed, int stored);	-daje ka�demu potrzebn� ilo�� jedzenia i odejmuje je od pola storedFood osady
			void isCollectorDead();						-sprawdza poziom g�odu
			void collectorsDie(int d);					-usuwa d element�w z wektora

	-Builder, dziedziczy po Human
		POLA:
			int tired;	-poziom zm�czenia
		Metody:
			Builder(int hunger = 100, int tired = 0);	-kontruktor
			int getTired()				-zwraca poziom zm�czenia
			void setTired(int tired)	-ustawia poziom zm�czenia
			void resetTired()			-zeruje poziom zm�czenia

	-BuildersTeam, dziedziczy po Builder
		POLA:
			vector<Builder*>buildersPack;	-zbi�r wszystkich �yj�cych budowniczych
		Metody:
			BuildersTeam();		-kontruktor
			int rebuildSettlement(int condition);	-je�eli poziom zm�czenia jest mniejszy od 6 ka�dy budowniczy zwi�ksza troche kondycje osady je�eli jest mniejsza od 1000
			int dailyHunger();							-zwraca ilo�� jedzenia kt�re potrzebowa� b�dzie ca�y wektor oraz odejmuje punkty g�odu ka�demu elementowi
			int dailyEating(int needed, int stored);	-daje ka�demu potrzebn� ilo�� jedzenia i odejmuje je od pola storedFood osady
			void isCollectorDead();						-sprawdza poziom g�odu
			void collectorsDie(int d);					-usuwa d element�w z wektora
	
	-Settlement
		POLA:
			int storedFood;			-zgromadzone jedzenie, kt�re jest rozdzielane na wszystkich mieszka�c�w
			int storedTreasure;		-zgromadzone skarby
			int condition;			-ataki indian mog� j� obni�y�
			bool isAlive = 1;		-je�eli condition spadnie do 0 to isAlive = 0 i symulacja sie ko�czy
		Metody:
			Settlement(int condition = 1000, int storedFood = 3600, int storedTreasure = 0);	-kontruktor
			int getStoredFood() { return storedFood; }
			int getStoredTreasure() { return storedTreasure; }
			int getCondition() { return condition; }
			void setStoredFood(int a) { this->storedFood += a; }
			void setStoredTreasure(int a) { this->storedTreasure += a; }
			void setCondition(int a) { this->condition += a; }
			void checkCondition(int condition);		-ustawia pole isAlive
			int howManyNewCollectorsCome(int c);	-sprawdza ilu nowych collector�w mo�e przyby� na podstawie warto�ci pola storedTreasure
			int howManyNewSoldiersCome(int s);		-sprawdza ilu nowych �o�nierzy mo�e przyby� na podstawie warto�ci pola storedTreasure
			int howManyNewBuildersCome(int b);		-sprawdza ilu nowych budowniczych mo�e przyby� na podstawie warto�ci pola storedTreasure

	-Events:
		Metody:
			Events();		-konstruktor
			void addCollectors(int l);		-dodaje l collector�w do wektora
			void addBuilders(int l);		-dodaje l budowniczych do wektora
			void addSoldiers(int l);		-dodaje l �o�nierzy do wektora
			void startSimulation();			-metoda ta ��czy w sobie wszystkie inne metody ca�ego projektu, ka�dy obr�t p�tli odpowiada jednemu dniu, w kt�rym zdarzaj� si� codzienne czynno�ci ale czasem mog� wylosowa� si� te� rzadsze


/////////////////////////////////////////////////////////////////////////////
