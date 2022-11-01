### Dynamic programming

Huffman kode
    - Lossless komprimeringsalgoritme
    - Brukt til komprimering av tekst
    - Hvert tegne vil få en binærkode
    - Ofte brukte tegn får en kortere kode enn mindre brukte tegn
    - Ingen koder er prefikser til andre koder
        - Om 01 er en kode vil ingen andre koder begynne med 01
    
    - Eksempel
        - La oss kode teksten: "alle studenter gleder seg til eksamen"
    
    - Algoritme
        1. Lag en løvnode i et binærtre av alle tegnene med antall forekomster
        2. Lag en min-heap av alle løvnodene
        3. Ta av to noder fra heapen
        4. Lag en foreldrenode til de to nodene i treet. Antall forekomster i den nye noden skal være summen av løvnodene
        5. Legg den nye noden inn i heapen
        6. Gjenta punkt 3 til 5 til det bare er en node på heapen

        Etter alt dette har vi et tre med de bokstavene som forekommer mest nært toppen
            - Sett 0 på alle kanter som går til venstre, og 1 på alle som går til høyre
            - Da vil bokstavene med størst forekomst ha liten kode (i dette eksempel har 'e' kode 00 og 8 forekomster)
    
Tries
    - en struktur vi bruker for å søke etter ord i en kjent tekst
    