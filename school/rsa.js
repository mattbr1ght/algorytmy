//let p, q, n, phi, e, d = 0;

function nwd(a, b){
    var pom = 0;
        
   while (a != b) {
     if (a < b) {
       pom = a; a = b; b = pom;
     }
     a = a - b;
   }
    return a;
}

function generate_keys(){
    p = 2;
    q = 7;
    n = p*q;
    phi = (p-1)*(q-1);
    for(i=2; i<phi; i++){
        if(nwd(i, n) == 1 && nwd(i, phi) == 1){
            e = i;
        }
    }
    d=1;
    while(((d*e) % phi) != 1 || d < 231){
        d++;
    }
    console.log(p, q, n, phi, e, d);
}

generate_keys();

function encrypt(){

}

function decrypt(){

}
