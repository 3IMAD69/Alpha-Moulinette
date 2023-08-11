#!/bin/bash

source ~/mini-moulinette/mini-moul/config.sh

function handle_sigint {
  echo "${RED}Script aborted by user. Cleaning up..."
  rm -R ../mini-moul
  echo ""
  echo "${GREEN}Cleaning process done.${DEFAULT}"
  exit 1
}

function run_norminette()
{
    local directory="$1"
    cd "$directory"

    if command -v norminette &> /dev/null; then
        norminette 
    else
        echo "norminette not found, skipping norminette checks"
    fi
}

if [[ "$#" -ge 1 && "$#" -le 2 ]]; then
  nn_arg="${2^^}"

  if [ "$nn_arg" = "-NN" ]; then
    # Skip running norminette
    echo "Skipping norminette checks"
  else
    # Run norminette and capture its output
    norminette_output=$(run_norminette "$PWD")
    norminette_exit_code=$?   
  
  if [ $norminette_exit_code -ne 0 ]; then
    printf "${RED}Error or warning detected in norminette output:\n${DEFAULT}"
    printf "$norminette_output\n"
    printf "${RED}Aborting the script.${DEFAULT}\n"
    exit 1
  else 
    printf "${GREEN}Norminette Status : OK!\n"
  fi
fi

  cp -R ~/mini-moulinette/mini-moul mini-moul

  trap handle_sigint SIGINT
	cd mini-moul
  ./test.sh "$1"
  rm -R ../mini-moul
else
  printf "${RED}You need to choose an assignment. e.g: mini C02\n${DEFAULT}"

fi

exit 1

