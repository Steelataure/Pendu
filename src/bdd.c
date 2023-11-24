#include <stdlib.h>
#include <mysql/mysql.h>

int bdd() {
    MYSQL *conn = mysql_init(NULL);

    if (conn == NULL) {
        fprintf(stderr, "mysql_init() a échoué\n");
        return 1;
    }

    // Connectez-vous à la base de données
    if (mysql_real_connect(conn, "votre_hote", "votre_utilisateur", "votre_mot_de_passe", "votre_base_de_donnees", 0, NULL, 0) == NULL) {
        fprintf(stderr, "Impossible de se connecter à la base de données : %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    printf("Connecté à la base de données avec succès\n");

    // Faites ici ce que vous avez besoin de faire avec la base de données

    // Fermez la connexion à la base de données
    mysql_close(conn);

    return 0;
}
