#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

string isValid(string s) {
    map<char,int> deletedMap;
    map<char,int> appearCountMap;
    map<int,int> appearCountAppearMap;
    int appearCountTargets = 0;

    for (int i = 0; i < s.size(); i++){
        appearCountMap[s[i]]++;
    }

    for (const auto &p : appearCountMap) {
        appearCountAppearMap[p.second]++;
    }

    int appearCountVariation = 0;
    for(const auto &p: appearCountAppearMap) {
        appearCountVariation++;
        if(appearCountVariation > 2){
            return "NO";
        }

        if(appearCountTargets == 0) {
            appearCountTargets = p.first;
        }else {
            if(p.second != 1 && appearCountAppearMap[appearCountTargets] != 1) {
                return "NO";
            }
        }

        if(appearCountTargets != p.first){
            if(abs(appearCountTargets - p.first) != 1 && appearCountAppearMap[appearCountTargets] != 1 ) {
                return "NO";
            }
        }

    }
    return "YES";

}


int main() {
    cout << "IS VALID " << isValid("ibfdgaeadiaefgbhbdghhhbgdfgeiccbiehhfcggchgghadhdhagfbahhddgghbdehidbibaeaagaeeigffcebfbaieggabcfbiiedcabfihchdfabifahcbhagccbdfifhghcadfiadeeaheeddddiecaicbgigccageicehfdhdgafaddhffadigfhhcaedcedecafeacbdacgfgfeeibgaiffdehigebhhehiaahfidibccdcdagifgaihacihadecgifihbebffebdfbchbgigeccahgihbcbcaggebaaafgfedbfgagfediddghdgbgehhhifhgcedechahidcbchebheihaadbbbiaiccededchdagfhccfdefigfibifabeiaccghcegfbcghaefifbachebaacbhbfgfddeceababbacgffbagidebeadfihaefefegbghgddbbgddeehgfbhafbccidebgehifafgbghafacgfdccgifdcbbbidfifhdaibgigebigaedeaaiadegfefbhacgddhchgcbgcaeaieiegiffchbgbebgbehbbfcebciiagacaiechdigbgbghefcahgbhfibhedaeeiffebdiabcifgccdefabccdghehfibfiifdaicfedagahhdcbhbicdgibgcedieihcichadgchgbdcdagaihebbabhibcihicadgadfcihdheefbhffiageddhgahaidfdhhdbgciiaciegchiiebfbcbhaeagccfhbfhaddagnfieihghfbaggiffbbfbecgaiiidccdceadbbdfgigibgcgchafccdchgifdeieicbaididhfcfdedbhaadedfageigfdehgcdaecaebebebfcieaecfagfdieaefdiedbcadchabhebgehiidfcgahcdhcdhgchhiiheffiifeegcfdgbdeffhgeghdfhbfbifgidcafbfcd");

    return 1;
}