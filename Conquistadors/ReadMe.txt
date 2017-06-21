========================================================================
    CONSOLE APPLICATION : Conquistadors Project Overview
========================================================================

Klasy:
	-Human
		POLA:
			- int hunger
		METODY:
			Human(int hunger);			-kontruktor
			int getHunger()				-podaje wartoœæ aktualnego stanu g³odu
			void setHunger(int hunger)	-ustawia nowy stan g³odu
			int random(int a, int b);	-losuje liczbe z przedzia³u a,b

	-Collector, dziedziczy po Human
		POLA:
			int backpackCapacity;	-tyle jedzenia i skarbów mo¿e na raz udŸwign¹æ collector
			int foundFood = 0;		-jedzenie które znalaz³ podczas jednego wyjœcia		
			int foundTreasure = 0;	-skarby które znalaz³ podczas jednego wyjœæia
		Metody:
			Collector();	-kontruktor 
			int getBackpackCapacity()	-podaje wartoœæ aktualnej pojemnoœci plecaka
			int getFoundFood()			-podaje iloœæ znalezionego jedzenia
			int getFoundTreasure()		-podaje iloœæ znalezionych skarbów
			void setBackpackCapacity(int backpackCapacity)	-ustawia wartoœæ pojemnoœci 
			void setFoundFood(int foundFood)	-ustawia iloœæ znalezionego jedzenia
			void setFoundTreasure(int foundTreasure) -ustawia iloœæ znalezionych skarbów
			void foodFound();			-dodaje 5 jednostek jedzenia do znalezionego jedzenia i zmniejsza o 5 pojemnoœæ plecaka
			void treasureFound();		-dodaje 1 jednostke skarbów do znalezionych skarbów i zmniejsza o 1 pojemnoœæ plecaka
			void clearBackpack();		- zeruje plecak

	-CollectorsTeam, dziedziczy po Collector
		POLA:
			vector<Collector*>collectorsPack;	-zbiór wszystkich ¿yj¹cych collectorów
		Metody:
			collectorsTeam();
			void collectorsGoOut();		-najpierw sprawdza czy wgl jacyœ collectorzy ¿yj¹, losuje ile razy znajd¹ jedzenie i skarby oraz jak du¿o
			int collectorsComeBackWithFood();		-zwraca iloœæ przyniesionego jedzenia (sume pól foundFood wszystkich collectorów w wektorze)
			int collectorsComeBackWithTreasure();	-j.w. ale skarbów
			void collectorsWereAttacked();			-losowo collectorzy mog¹ byæ lub nie napadniêci przez indian, losowa ich liczba wtedy ginie
			int dailyHunger();							-zwraca iloœæ jedzenia które potrzebowaæ bêdzie ca³y wektor oraz odejmuje punkty g³odu ka¿demu elementowi
			int dailyEating(int needed, int stored);	-daje ka¿demu potrzebn¹ iloœæ jedzenia i odejmuje je od pola storedFood osady
			void isCollectorDead();						-sprawdza poziom g³odu
			void collectorsDie(int d);					-usuwa d elementów z wektora

	-Soldier, dziedziczy po Human
		POLA:
			int combatPoints; -punkty walki, je¿eli jakiœ ¿o³nierz stoczy³ troche walk to pokona wiêcej indian
		Metody:
			Soldier(int health = 100, int hunger = 100, int combatPoints = 10);	-konstruktor
			int getcombatPoints()	zwraca iloœæ punktów
			void setCombatPoints(int combatPoints) ustawia iloœæ punktów
			int combatPointsMeaning(int combatPoints); algorytm do przetworzenia punktów na wp³yw w walce

	-SoldiersTeam, dziedziczy po Soldier
		POLA:
			vector<Soldier*>soldiersPack;	-zbiór wszystkich ¿yj¹cych ¿o³nierzy
		Metody:
			SoldiersTeam();					-konstruktor
			int indiansAttack(int days);	-losuje czy indianie zaatakowali osade oraz ich liczbe na podstawie dnia symulacji
			int battleResult(int x);		-zwraca iloœæ poleg³ych ¿o³nierzy
			int dailyHunger();							-zwraca iloœæ jedzenia które potrzebowaæ bêdzie ca³y wektor oraz odejmuje punkty g³odu ka¿demu elementowi
			int dailyEating(int needed, int stored);	-daje ka¿demu potrzebn¹ iloœæ jedzenia i odejmuje je od pola storedFood osady
			void isCollectorDead();						-sprawdza poziom g³odu
			void collectorsDie(int d);					-usuwa d elementów z wektora

	-Builder, dziedziczy po Human
		POLA:
			int tired;	-poziom zmêczenia
		Metody:
			Builder(int hunger = 100, int tired = 0);	-kontruktor
			int getTired()				-zwraca poziom zmêczenia
			void setTired(int tired)	-ustawia poziom zmêczenia
			void resetTired()			-zeruje poziom zmêczenia

	-BuildersTeam, dziedziczy po Builder
		POLA:
			vector<Builder*>buildersPack;	-zbiór wszystkich ¿yj¹cych budowniczych
		Metody:
			BuildersTeam();		-kontruktor
			int rebuildSettlement(int condition);	-je¿eli poziom zmêczenia jest mniejszy od 6 ka¿dy budowniczy zwiêksza troche kondycje osady je¿eli jest mniejsza od 1000
			int dailyHunger();							-zwraca iloœæ jedzenia które potrzebowaæ bêdzie ca³y wektor oraz odejmuje punkty g³odu ka¿demu elementowi
			int dailyEating(int needed, int stored);	-daje ka¿demu potrzebn¹ iloœæ jedzenia i odejmuje je od pola storedFood osady
			void isCollectorDead();						-sprawdza poziom g³odu
			void collectorsDie(int d);					-usuwa d elementów z wektora
	
	-Settlement
		POLA:
			int storedFood;			-zgromadzone jedzenie, które jest rozdzielane na wszystkich mieszkañców
			int storedTreasure;		-zgromadzone skarby
			int condition;			-ataki indian mog¹ j¹ obni¿yæ
			bool isAlive = 1;		-je¿eli condition spadnie do 0 to isAlive = 0 i symulacja sie koñczy
		Metody:
			Settlement(int condition = 1000, int storedFood = 3600, int storedTreasure = 0);	-kontruktor
			int getStoredFood() { return storedFood; }
			int getStoredTreasure() { return storedTreasure; }
			int getCondition() { return condition; }
			void setStoredFood(int a) { this->storedFood += a; }
			void setStoredTreasure(int a) { this->storedTreasure += a; }
			void setCondition(int a) { this->condition += a; }
			void checkCondition(int condition);		-ustawia pole isAlive
			int howManyNewCollectorsCome(int c);	-sprawdza ilu nowych collectorów mo¿e przybyæ na podstawie wartoœci pola storedTreasure
			int howManyNewSoldiersCome(int s);		-sprawdza ilu nowych ¿o³nierzy mo¿e przybyæ na podstawie wartoœci pola storedTreasure
			int howManyNewBuildersCome(int b);		-sprawdza ilu nowych budowniczych mo¿e przybyæ na podstawie wartoœci pola storedTreasure

	-Events:
		Metody:
			Events();		-konstruktor
			void addCollectors(int l);		-dodaje l collectorów do wektora
			void addBuilders(int l);		-dodaje l budowniczych do wektora
			void addSoldiers(int l);		-dodaje l ¿o³nierzy do wektora
			void startSimulation();			-metoda ta ³¹czy w sobie wszystkie inne metody ca³ego projektu, ka¿dy obrót pêtli odpowiada jednemu dniu, w którym zdarzaj¹ siê codzienne czynnoœci ale czasem mog¹ wylosowaæ siê te¿ rzadsze


/////////////////////////////////////////////////////////////////////////////
