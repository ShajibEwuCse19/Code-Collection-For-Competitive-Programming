    getline(cin,str);///input a word or multiple word (sentences).

    map<string,int>cntWord;///count frequency of word.

    string word;///store all the word one by one.
    stringstream s(str);///divided the sentence into words.

    while(s >> word)cntWord[word]++;///take a word and count its frequency.

    ///map<string,int> :: iterator it;
    ///for(auto it=cntWord.begin(); it!=cntWord.end();it++)cout<<it->first<<" = "<<it->second<<endl;

    for(auto i : cntWord)cout<<i.first << " = " <<i.second<<endl;

    ///Input : Geeks for Geeks
    ///Output: 
    ///Geeks -> 2 
    ///for -> 1
