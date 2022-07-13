//https://www.youtube.com/watch?v=a8ZB-TPB6EU

#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel {
private:
	string Name;
	string OwnerName;
	int SubscribersCount;
	list<string> PublishedVideoTitles;

public:
	YouTubeChannel(string name, string ownerName) {
		Name = name;
		OwnerName = ownerName;
		SubscribersCount = 0;
	}
	void GetInfo() {
		cout << "Name: " << Name << endl;
		cout << "OwnerName: " << OwnerName << endl;
		cout << "SubscribersCount: " << SubscribersCount << endl;
		cout << "Videos: " << endl;
		for (string videoTitle : PublishedVideoTitles) {
			cout << videoTitle << endl;
		}
	}
	void Subscribe() {
		SubscribersCount++;
	}

	void Unsubscribe() {
		if(SubscribersCount>0)
			SubscribersCount--;
	}

	void PublishVideo(string title) {
		PublishedVideoTitles.push_back(title);
	}
};

int main()
{
	YouTubeChannel ytChannel("CodeBeauty", "Saldina");
	ytChannel.PublishVideo("C++ for beginners");
	ytChannel.PublishVideo("HTML & CSS for beginners");
	ytChannel.PublishVideo("C++ OOP");

	ytChannel.Subscribe();
	ytChannel.Subscribe();
	ytChannel.Subscribe();
	ytChannel.Unsubscribe();
	ytChannel.Subscribe();

	ytChannel.GetInfo();

	system("pause>0");
}