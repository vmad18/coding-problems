void generateWords(string s, string wb, unordered_map<string, bool> &words){
    if(words[s]) return;
    words[s] = true;
    if(wb=="") return; 
    for(int i=0;i<wb.size();i++){
        string clone = wb;
        string t = clone.substr(i,1);
        clone.erase(i,1); 
        string ns = s+t; 
        if(!words[ns])
            generateWords(ns, clone, words); 
    }
}

int numTilePossibilities(string tiles) {
    unordered_map<string, bool> words; 
    generateWords("",tiles,words); 
    return words.size()-1;
}