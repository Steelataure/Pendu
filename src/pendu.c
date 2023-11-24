void pendu(tentiatives){
    if (tentatives==0){
        printf(" ==========Y= ");
    }
    if (tentatives<=1){
        printf(" ||/       |  ");
    }
    if (tentatives<=2){
        printf(" ||        0  ");
    }
    if (tentatives<=3){
        printf(" ||       /|\\ ");
    }
    if (tentatives<=4){
        printf(" ||       /|  ");
    }
    if (tentatives<=5){
        printf("/||           ");
    }                 
    if (tentatives<=6){
        printf("==============\n");
    }
}