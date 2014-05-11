Konfiguracja Projektu GjeTeA pod Windowsem
======
###Tworzymy nowy projekt w Visual Studio:

- Visual C++ -> Console Application Win32 
- Zaznaczamy "Empty Project" i odznaczamy "Security Development Lifecycle (SDL) checks"
- Klikamy Finish

###Dodajmy git'a i ściagamy pliki:
- Na Windowsie sciągamy klienta Git za strony: http://msysgit.github.io/
- Podczas intsalacji zaznaczamy instalacje Git Bash'a oraz opcjonalnie Git GUI
- Po instalacji odpalamy Git Bash'a
- W konsoli wchodzimy do katalogu gdzie będą znajdować się pliki
w Visual Studio będzie to katalog wg schemtu: 

        "sciezka_do_katalogu_z_projektami/Nazwa_projektu/Nazwa_projektu"
	np w przypadku:  C://projects/ProjektProgramu/ProjektProgramu

		cd /C/ProjektProgramu/ProjektProgramu
- Inicjalizujemy projekt Gitza pomocą komendy:

        git init
W tym miejscu kilka słów o "gicie":

	Git składa się z dwóch rodzajów repozytorium: lokalnego i zdalnego. Wygląda to tak, że pliki wersjonujemy na naszym lokalnym repozytorium, a potem dopiero zmiany wrzucamy do repoztorium zdalnego w naszym przypadku hostowanego na github.com		komenda git init tworzy nam właśnie takie repozytorium lokalne
- Następnym krokiem jest podłączenie do naszego repozytorium, repozytorium zdalnego:

		git remote add origin https://github.com/qba10/GjeTeA.git
		
- Ok, jako że nasze repozytorium lokalne jest puste musimy pobrać pliki z serwera
	Do tego służy komenda:

        git pull
        
Będziemy jej  używać również podczas odświerzania naszego repozytorium lokalnego

- Jak możesz w tej chwili zauważyć, w naszym katalogu nie ma jescze żadanych plików. Żeby się pojawiły musisz wybrać branch'a z któego chcesz korzystać.
Co to jest branch?
Branch jest to katalog roboczy z kopią wersjonowanych plików. Ideą branchy jest wrowadzanie równoległe zmian w kodzie.
Na koniec branche łączymy z branchem gównym który u nas nazywa się "master"

Komendy związane że branchami:

    	git checkout nazwa_brancha - przełącza nas na wybrany branch
		git checkout -b nazwa_nowego_brancha - tworzy nowy branch
		git branch - pokazuje lokalne branche
		git branch -a pokazuje loklane i zdalne branche
My przełączamy się aktualnie na branch "master"
		
		git checkout master
W tym momencie powinny pokazać się pliki w twoim katalogu

Żeby zobaczyć aktualny stan repozytorium loklanego używamy komendy:
		
		git status
##Intergacja Git'a z Visual Studio
Niestety nie potrafię w tej chwili w jakiś logiczny sposób zintegrować git'a z Visual Studio 
	tak więc nowe pliki sciągniete z github'a na razie  dodajemy ręcznie do projektu (Solution Explorer -> *right click* -> add new -> existing files)
##Ściągniecie potrzebnych bibliotek

* Tworzymy jakiś katlog gdzieś na komputerze i sciagmy tam liby potrzebne do kompilacji (w moim przypadku będzie to *C:/liby* )

	
W Git Bashu wklepujemy następujące kroki:
		cd /C
		mkdir liby
		cd liby
		git clone https://github.com/qba10/GjeTeA.git -b windows_lib

##Konfiguracja projektu Visual Studio	
* W Solution Explorer kilkamy prawym na nazwe projektu, a nstępnie Propertis
* Wchodzimy do zakładki Configuration Propertis-> C++ ->General 
* Do Additional Include Directories dodajmy scieżki: 

		C:\liby\GjeTeA\SFML-2.1\include
		C:\liby\GjeTeA\jsoncpp
- Wchodzimy do zakładki Configuration Propertis-> Linker -> General
- Do Additional Library Directories dodajmy scieżki:

		C:\liby\GjeTeA\SFML-2.1\lib
		C:\liby\GjeTeA\jsoncpp\Debug\bin
- Wchodzimy do zakładki Configuration Propertis-> Linker -> Input
- Do Additional Dependencies dodajmy :

		sfml-window-d.lib
		sfml-system-d.lib
		sfml-graphics-d.lib
		sfml-network-d.lib
		jsoncpp.lib
- Zastosowujemy zmiany
- Pliki DLL z katalogu *C:\liby\GjeTeA\SFML-2.1\bin* kopiujemy do folderu z plikiem wykonywalnym naszej aplikacji albo do C:\windows\system32
- Zmieniamy solution platforms na x64 (liby są 64-bitowe, na win32 wywali wam błąd linkowania Error 2019)
- Teraz Robimy Build i mamy działąjący program

## Uwagi końcowe
- nowe zmiany wrucamy albo na swojego brancha albo tworzymy nowy
- komenda 
        git status
wyswietla aktualny stan plików w loklanym repozytorium oraz informacje na jakim branchu jestesmy
- Poradnik jak używać git'a na stronie: http://www.wykop.pl/ramka/1003529/git-pieknie-przygotowany-przewodnik/
