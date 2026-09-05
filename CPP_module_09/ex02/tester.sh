#!/bin/bash

EXEC="./PmergeMe"

# Vérifie que l'exécutable existe
if [ ! -f "$EXEC" ]; then
    echo "Erreur : L'exécutable $EXEC est introuvable. As-tu fait un 'make' ?"
    exit 1
fi

check_test() {
    local test_name="$1"
    shift
    local input="$@"

    echo "--- $test_name ---"
    
    # Exécute ton programme et récupère la ligne "After:"
    output=$($EXEC $input 2>&1)
    after_line=$(echo "$output" | grep "^After:" | sed 's/After:[ \t]*//')
    
    if [ -z "$after_line" ]; then
        echo -e "Résultat : \033[31mKO (Ligne 'After:' introuvable ou crash)\033[0m\n"
        return
    fi

    # Vérifie mathématiquement si c'est trié
    is_sorted=1
    prev=-1
    for num in $after_line; do
        if (( num < prev )); then
            is_sorted=0
            break
        fi
        prev=$num
    done

    if [ $is_sorted -eq 1 ]; then
        echo -e "Résultat : \033[32mOK (Tri validé ✅)\033[0m\n"
    else
        echo -e "Résultat : \033[31mKO (Erreur de tri ❌)\033[0m"
        echo "Ta sortie  : $after_line"
        echo "Attendue   : $(echo $input | tr ' ' '\n' | sort -n | tr '\n' ' ')"
        echo ""
    fi
}

# Lancement de la batterie de tests
check_test "Test 1 : Pair" 4 9 2 8 5 1 7 3
check_test "Test 2 : Impair (straggler)" 15 3 9 22 1 8 14 7 10
check_test "Test 3 : Doublons multiples" 7 3 5 7 2 5 7 9 3 1
check_test "Test 4 : Pire cas (Inversé)" 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
check_test "Test 5 : Déjà trié" 1 2 3 4 5 6 7 8 9 10 11 12
check_test "Test 6 : Tous identiques" 42 42 42 42 42 42 42 42
check_test "Test 7 : Limite Jacobsthal" 45 12 89 23 67 4 91 34 56 78 19 2 99 41 62 8 73 27 50 84 15 38 6