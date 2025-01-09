function encrypt(str, off){
    let result=""
    for (let i = 0; i < str.length; i++)
    {
        let code = str.charCodeAt(i);

        if (code >= 65 && code <= 90)
        {
            let offset = off % 26;
            const shifted_code = (code + offset-65) % 26 + 65;
            let balancer = shifted_code < 65 ? 26 : 0;
            let ch = String.fromCharCode(shifted_code + balancer);
            result += ch;
        }
        else if(code >= 97 && code <= 122)
        {
            let offset = off % 26;
            const shifted_code = (code + offset-97) % 26 + 97;
            let balancer = shifted_code < 97 ? 26 : 0;
            let ch = String.fromCharCode(shifted_code + balancer);
            result += ch;
        }
        else if(code >= 48 && code <= 57)
        {
            let offset = off % 10;
            const shifted_code = (code + offset-48) % 10 + 48;
            let balancer = shifted_code < 48 ? 10 : 0;
            let ch = String.fromCharCode(shifted_code + balancer);
            result += ch;
        }
        else {
            let ch = String.fromCharCode(code);
            result += ch;
        }
    }
    return result;
}

function brute_force_cesar(text){
    console.log("brute forcing the cypher " + text + " ...");
    for(i = 0; i < 26; i++){
        console.log("Shift : " + (i+1) + " | " + encrypt(text, -i-1));
    }
    console.log("finished.");
}

// Driver code
const text = "Hi, hello WORLD! Hi, h3ll0 w0rlD! aAzZ09  abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const offset = 94;
const encrypted = encrypt(text, offset);
console.log("Text      : " + text);
console.log("Shift     : " + offset);
console.log("Cipher    : " + encrypted);
console.log("Decrypted : " + encrypt(encrypted, -offset));
console.log();
brute_force_cesar(encrypted);
