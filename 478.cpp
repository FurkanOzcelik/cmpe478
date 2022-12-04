#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>

using namespace std;

#define alpha 0.2
#define epsilon 0.000001

int main (int argc, char* argv[])
{


// Create a text string, which is used to output the text file
  string myText;
  vector<string> textFromFile;

	// Read from the text file
  ifstream MyReadFile("sa.txt");

	// Use a while loop together with the getline() function to read the file line by line
  while (getline (MyReadFile, myText)) {
	  // Output the text from the file
  	textFromFile.push_back(myText);
  }

  map<string, vector<string>> edges;
  vector<string> keys;
  for (int i = 0; i < textFromFile.size(); i++) {
    string line = textFromFile[i];
    string str1 = "", str2 = "", key = "";
  for (auto a : line)
  {
    if (a == '\t')
    {
      str1 = key;
      key = "";
      //cout << key << endl
    }
    else {
      key = key + a;
    }
  }
  str2 = key;
	    	
	if(find(keys.begin(), keys.end(), str1) != keys.end()) {
    /* v contains str1 */
	} else {
    keys.push_back(str1);
	}


  if (edges.count(str1)) {
    edges[str1].push_back(str2);
  }
  else {
    //edges[str1] = str2;
    edges[str1].push_back(str2);
//        	edges.insert(pair<string,vector<string> >(str, vector<string>()));
  }
      
  }
    
  //for (auto const& x : map)
  //{
      //std::cout << x.first  // string (key)
    //      << ':' 
    //      << x.second // string's value 
    //      << std::endl;
  //}
  
  int n = edges.size();
  cout << n << endl;

  double P[n][n];
  
  for(int k = 0; k < keys.size(); k++){
    string currentKey = keys[k];
    int edgesToKey = 0, edgesFromKey = 0;
    for (int i = 0; i < keys.size(); i++) {
        
      if(keys[i] == currentKey){
        //cout << "Size: " << edges[currentKey].size() << endl;
        edgesFromKey = edgesFromKey + edges[currentKey].size();
      }
      else{
        if(find(edges[keys[i]].begin(), edges[keys[i]].end(), keys[k]) != edges[keys[i]].end()) {
          //cout << "Key: " << keys[i] << " =>> " << keys[k] << endl;
          edgesToKey++;
        }
          //for(int j = 0; j < keys.size(); j++){
          
          //	if(find(edges[keys[i]].begin(), edges[keys[i]].end(), keys[j]) != edges[keys[i]].end()) {
      //    		P[i][j] = 1;
      //	}else{
      //		P[i][j] = 0;
      //	}
          
          //}
      }
    
      for (vector<string>::iterator t=edges[keys[i]].begin(); t!=edges[keys[i]].end(); ++t) {
      //   cout << "Key: " << keys[i] << " =>>> " ;
      //  cout<<*t<<endl;
      }
    }
    cout << edgesToKey << "/" << edgesFromKey << "\t";
    P[0][k] = (double)edgesToKey/(double)edgesFromKey;
    	
  }
    
  cout << endl ;
  
  double total = 0;
    
  for(int iter = 0; iter < 10; iter++){
  	for(int i = 0; i < n; i ++){
		  double x = P[0][i];
		  //cout << P[0][i] * 0.2 + 0.8 << "-" << x << "=" << P[0][i] * 0.2 + 0.8 - x << endl;
		  total += P[0][i] * 0.2 + 0.8 - x;
		  P[0][i] = P[0][i] * 0.2 + 0.8;
		  //cout << total << endl;
		}
		cout << "Iter: " << iter << " => Total: " << total << endl;
		total = 0;
  }
  
    
  return 0;
}
