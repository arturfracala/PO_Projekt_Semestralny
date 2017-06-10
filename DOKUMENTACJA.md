Projekt semestralny z programowania obiektowego – dokumentacja techniczna

Opis wstępny:
Przed przeczytaniem dokumentacji technicznej warto przeczytać wcześniej plik readme dostępny na stronie. 
Na mechanizm działania projektu składa się 5 klas.  Pierwsza jest interfejsem stworzonym pod funkcjonowanie 3 kolejnych,
których obiekty będą symulowały udział w turnieju. Będzie ona posiadała metody, które zmieniają wartości zmiennych klasowych
oraz takie, które je zwracają. Wszystkie zmienne będą złożone w strukturę. W niej będą się one dzieliły na takie, które charakteryzują
klasę i takie, które pomagają w obsłudze zdarzeń. Interfejs będzie posiadał również zmienną plikową. Ostatnia będzie obsługiwała
komunikacje z użytkownikiem, wyświetlanie wszystkich zagnieżdżeń menu, wykonywanie zdarzeń w zależności od polecenia użytkownika.

Opis ważniejszych metod klasy Fighter_Interface:
- void health_max() – przywraca obiektowi domyślną maksymalną wielkość punktów życia (przechowywane w zmiennej health).
- void max_strength() – przywraca obiektowi domyślną maksymalną wielkość punktów wytrzymałości (przechowywane w zmiennej strength).
- void show_parameters() – wyświetla w konsoli wartości zmiennych klasowych charakteryzujących dany obiekt.
- wszystkie funkcje ze słowem return w nazwie zwracają zgodnie z drugim członem nazwy odpowiednią wartość zmiennej.
- wszystkie funkcje ze słowem change w nazwie zmieniają zgodnie z drugim członem nazwy odpowiednią wartość zmiennej. 
W ich wypadku jako parametr należy podać wartość o jaką chcemy zmienić to zmienną.

Opis ważniejszych funkcji klas Boxer, Swarmer, Brawler:
- wszystkie te klasy posiadają metody wirtualne Jab(), Hook() oraz Uppercut(). Są to metody symulujące ciosy. Różnią się one siłą
(odbieraniem punktów życia przeciwnikowi) oraz wartością zabieranych punktów wytrzymałości obiektowi, który te metody wywołuje. 
Jako parametr do wszystkich tych funkcji należy podać wskaźnik (Fighter_Interface*) na obiekt który będzie symulował bycie
przeciwnikiem, obiektem na który ta funkcja będzie działa. 
- virtual void Clinching() – funkcja dodaje punkty wytrzymałości i życia dla obiektu na rzecz którego została wykonana.
Jest to jedna z możliwych do wykonania funkcji dla użytkownika

Opis ważniejszych funkcji klasy Board:
- void change_stage(stage) – funkcja ta zmienia zmienną klasową typu stage. Jako parametr musimy podać jeden z czterech wartości enum.
Do wyboru jest opening, quarterfinal, semifinal oraz finall. 
- void panel(Fighter_Interface*[8]) – funkcja ta wyświetla główne menu gry oraz główną pętle programu. Znajduje się w niej switch, 
który obsługuje opcje wybierane przez użytkownika. Jako parametr funkcja ta przyjmuje tablicę wskaźników typu Fighter_Interface 
- void replacing(Fighter_Interface*,Fighter_Interface *) – metoda ta zamienia obiekty na które wskazują wskaźniki podawane jako parametr.
- void auto_fight(Fighter_Interface*,Fighter_Interface *)  – metoda symuluje walkę botów w turnieju. Walka ta kończy się gdy punkty
życia jednego obiektu spadną do zera. Wtedy zmienna logiczna „bool won” obiektu zwycięskiego przyjmuje wartość true.
- void select_punch(int ,Fighter_Interface*,Fighter_Interface *)  – funkcja obsługuje ciosy losowane przez komputer w symulacji walki. 
Jako parametry używa kolejno zmiennej char, która przechowuje informacje który cios ma zostać użyty, wskaźnik Fighter_Interface
na obiekt (postać) agresora, oraz wskaźnik na obiekt przeciwnika.
- void select_name() – metoda pobiera imię gracza z klawiatury.
- void player_fight(char,Fighter_Interface*,Fighter_Interface *)  – metoda obsługuje ciosy wybierane przez gracza z klawiatury.
Jako parametry przyjmuje zmienna char, która przechowuje wybór ciosu, oraz dwa wskaźniki na obiekty gracza i bota, który ten cios
ma przyjąć. 
- void fight(Fighter_Interface*,Fighter_Interface *)  – metoda obsługująca wyświetlanie panelu walki, informacji o stanie postaci
i ich parametrach, oraz wybór ciosu
- void game(Fighter_Interface*[8]) – metoda łącząca wszystkie funkcje w całość, wywołuje odpowiednie funkcje i metody w zależności 
od wyników pojawiających się w czasie trwania turnieju. Zapewnia też komunikacje z użytkownikiem wywołując metody pozwalające na
przykład na podglądanie drabinki turniejowej. Jako parametr przyjmuje tablicę wskaźników na obiekty symulujące udział w turnieju. 
- void tournament_ladder(Fighter_Interface*[8]) – funkcja wyświetla drabinkę turniejową
- save_points(Fighter_Interface*) – funkcja zapisuje punkty obiektu do pliku tekstowego
