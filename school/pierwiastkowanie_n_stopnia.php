<?php

$n = readline("Podaj stopień pierwiastka : ");
#is_positive_int($n);

$a = readline("Podaj liczbę do obliczenia pierwiastka : ");
is_positive_int($a);

function is_positive_int($a){
  if (!is_numeric($a)) { //wcześniej !ctype_digit($a)
    echo "Nie podano poprawnej liczby";
    exit(0);
  }
  if ($a <= 0) {
    echo "Podana liczba musi być liczbą dodatnią";
    exit(0);
  }
  return true;
}

function n_root_iterative($a, $n)
{
  $buffer = -1;
  $i = 1;
  $last_x = $a;
  $continue = null;
  $max_k = 100;
  while ($buffer != $last_x || ($i <= $max_k and $continue == true) || is_null($continue)) {
    if(is_null($continue)){
      $read = readline("Czy kontynuować liczenie pomimo powtarzalności ostatnich wyników (y/n)? : ");
      $continue = ($read == "y" ? true : ($read == "n" ? false : null));
      continue;
    }
    echo $i++ . ". " . $last_x . " \n";
    $buffer = $last_x;
    $last_x = (1 / $n) * ((($n-1)*$last_x) + ($a / ($last_x ** ($n-1))));
  }
  return $last_x;
}

echo "funkcja iteratywna\n";
echo "\npierwiastek z $a wynosi : " . n_root_iterative($a, $n);

