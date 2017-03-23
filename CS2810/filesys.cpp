#include <bits/stdc++.h>

using namespace std;

class FileorFolder{
	protected:
		string name;
		string type;
		

	public:
		FileorFolder(string s):name(s){}

		inline string getName(){return name;}

		
};

bool cmpFileFolder(FileorFolder* a, FileorFolder* b){return a->getName()< b->getName();} 


class File : public FileorFolder{
	private:
		

	public:
		File(string s):FileorFolder(s){

		}
					
		
};

class Folder : public FileorFolder{
	private:
		std::vector<File*> fileList;
		std::vector<Folder*> folderList;
		Folder* parent;
		bool isroot;
		

	public:
		string path;

		string printPath();

		Folder(string s, Folder* par,bool iroot=false):FileorFolder(s){
			isroot = iroot;
			parent = par;
			if(isroot) path="/";
			else
				path=parent->printPath()  + name+ "/";
		}
		Folder* findFolder(string s);
		File* findFile(string s);
		File* addFile(string s);
		Folder* addFolder(string s);

		void deleteFileorFolder(string s);

		Folder* gotoDirectory(string s){
			if(s=="..") {
				if(!isroot)
					return parent;
				else

					return this;

			}
			Folder *dest;
			if((dest = findFolder(s))!=nullptr){
				return dest;
			}
			else{
				cout<<"Does not exist\n";
				return this;
			}
		}

		void printcontents();
		
		
};

bool notgoodname(string s){
	for(char c: s){
		if((c=='_') || (c<='z' && c>='a') || (c<='Z'&& c>='A') || (c<='9' && c>='0'));
		else return true;
	}

	return false;
}

void Folder::printcontents(){
	std::sort(folderList.begin(), folderList.end(), cmpFileFolder);
	
	for(auto ptr: folderList){
		cout<<ptr->getName()<<" ";
	}
	std::sort(fileList.begin(), fileList.end(), cmpFileFolder);

	for(auto ptr: fileList){
		cout<<ptr->getName()<<" ";
	}
	cout<<endl;
}

string Folder::printPath(){
	if(isroot) return "/";
	else
		return path.substr(0,path.length()-1);
}

Folder* Folder::findFolder(string nm){
	for(auto it = folderList.begin(); it!= folderList.end(); it++){
		if((*it)->getName() == nm) return *it;
	}
	return nullptr;
}

File* Folder::findFile(string nm){
	for(auto it = fileList.begin(); it!= fileList.end(); it++){
		if((*it)->getName() == nm) return *it;
	}
	return nullptr;
}

Folder* Folder::addFolder(string nm){
	if(notgoodname(nm)) {cout<<"Exists\n";return nullptr;}
	FileorFolder* res1,*res2;
	if((res1=findFolder(nm))!=nullptr || (res2=findFile(nm))!=nullptr){
		cout<<"Exists\n";
		return nullptr;
	}
	else
	{
		Folder* res;
		folderList.push_back(res = new Folder(nm,this));
		std::sort(folderList.begin(), folderList.end(), cmpFileFolder);
		return res;
	}
}

File* Folder::addFile(string nm){
	if(notgoodname(nm)) {cout<<"Exists\n";return nullptr;}
	FileorFolder* res1,*res2;
	if((res1=findFolder(nm))!=nullptr || (res2=findFile(nm))!=nullptr){
		cout<<"Exists\n";
		return nullptr;
	}
	else
	{
		File* res;
		fileList.push_back(res = new File(nm));
		std::sort(fileList.begin(), fileList.end(), cmpFileFolder);
		return res;
	}
}

void Folder::deleteFileorFolder(string nm){
	FileorFolder* found = nullptr;
	if((found = findFolder(nm)) != nullptr){
		 folderList.erase(std::find(folderList.begin(), folderList.end(), found));
		 std::sort(folderList.begin(), folderList.end(), cmpFileFolder);
	}
	else if((found = findFile(nm)) != nullptr){
		fileList.erase(std::find(fileList.begin(), fileList.end(), found));
		std::sort(fileList.begin(), fileList.end(), cmpFileFolder);
	}
	else cout<<"Does not exist\n";
}

void tokenise(string& s, string& s1, string& s2){
	string delimiter = " ";
	s1=s.substr(0,s.find(delimiter));
	s.erase(s.begin(),s.begin() + s.find(delimiter)+1);
	while(s[0]==' ') s.erase(s.begin());
	if(!s.empty())
		s2 = s.substr(0,s.find(delimiter));
}


int main(int argc, char const *argv[])
{
	
	Folder* current = new Folder("/",nullptr,true);
	string s,s1,s2;

	while(getline(cin,s)){
		tokenise(s,s1,s2);

		if(s1=="mkdir") current->addFolder(s2);
		else if(s1 == "touch") current->addFile(s2);
		else if(s1 == "cd") current = current->gotoDirectory(s2);
		else if(s1 == "pwd") cout<<current->printPath()<<endl;
		else if(s1 == "rm") current->deleteFileorFolder(s2);
		else if(s1 == "ls") current->printcontents();


	}
	return 0;
}
