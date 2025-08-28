#include<iostream>
#include<vector>
#include<string>

using namespace std;

    vector<int> findIPClass(vector<string> & ip_addresses){
        
        int n = ip_addresses.size();
        vector<int> IPClass(n);
        for(int i = 0 ; i < n ; i++){
            string currAddress = ip_addresses[i];
            int currAddressSize = currAddress.size();
            vector<string> octets;
        string currOctet = "";                     
        for(int j = 0 ; j < currAddressSize;j++){
            if(currAddress[j] == '.'){
                octets.push_back(currOctet);
                currOctet = "";
            }
            else currOctet += currAddress[j];
            if(j == currAddressSize - 1) octets.push_back(currOctet);
        }
            if(octets.size() != 4) {
                IPClass[i] = -1;
                continue;
            }
            bool invalidAdd = false;
            for( string s : octets){
                if(s.empty()){            
                    invalidAdd = true;
                    break;
            }
                if(s.size() > 1 && s[0] == '0'){
                    invalidAdd = true;
                    break;
                }
                int numOctet = stoi(s);
                if(numOctet < 0 || numOctet > 255){
                    invalidAdd = true;
                    break;
                }

            }
            if(invalidAdd){
                IPClass[i] = -1;
                continue;
            }
            string firstOctet = octets[0];
            int firstNumOctet = stoi(firstOctet);

        if(firstNumOctet < 128) IPClass[i] = 1;
        else if(firstNumOctet < 192) IPClass[i] = 2;
        else if(firstNumOctet < 224) IPClass[i] = 3;
        else if(firstNumOctet < 240) IPClass[i] = 4;
        else if(firstNumOctet < 256) IPClass[i] = 5;
        }
        return IPClass;
    }
int main(){
    vector<string> ip_addresses = { "192.168.1.1",
    "255.255.255.255",
    "256.100.50.25",
    "192.168.1",
    "0.0.0.0",
    "01.02.03.04",
    "192.168.001.001",
    "123.045.067.089",
    "10.0.0.256",
    "172.16.254.1",
    "300.1.1.1",
    "192.168.1.256",
    "192.168.0.12",
    "192.168.0.12.80",
    "127.0.0.1",
    "255.255.255.256",
    "8.8.8.8",
    "192.168.0.01",
    "192.168..1"};
    vector<int> result = findIPClass(ip_addresses);

    for(int i : result)
        cout<<i<< "  ";
    return 0;
}