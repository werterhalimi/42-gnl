# 42-gnl

Ce code est une implémentation de la fonction get_next_line(), qui permet de lire une ligne d'un fichier à partir d'un descripteur de fichier (file descriptor, ou fd en anglais) en un seul appel.

La fonction commence par vérifier si le descripteur de fichier est valide et initialise le buffer de lecture si nécessaire. Elle lit ensuite le buffer jusqu'à rencontrer un saut de ligne ('\n') ou la fin du fichier, en ajoutant chaque caractère lu à la chaîne de caractères retour (ret). Si elle rencontre un saut de ligne, elle retourne la chaîne ret. Sinon, elle lit de nouveaux données depuis le fichier et recommence jusqu'à trouver un saut de ligne ou la fin du fichier.

La fonction buffer_map() est utilisée pour copier les données restantes du buffer dans un nouveau buffer, afin de ne pas perdre les données qui n'ont pas encore été lues. La fonction ft_create_buffer() s'assure que le buffer est initialisé et rempli avec les données du fichier. La fonction ft_read_buffer() lit les données du buffer et ajoute chaque caractère à ret jusqu'à rencontrer un saut de ligne, auquel cas elle retourne 1 pour indiquer que la ligne a été entièrement lue. La fonction ft_process_buffer() gère le cas où la fin du fichier est atteinte et libère le buffer si nécessaire.
