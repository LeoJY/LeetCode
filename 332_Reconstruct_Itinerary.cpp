//332. Reconstruct Itinerary
//Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
//Note:
//If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
//All airports are represented by three capital letters (IATA code).
//You may assume all tickets form at least one valid itinerary.

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(auto ticket : tickets){
        	myMap[ticket.first].insert(ticket.second);
        }
        visit("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
private:
	unordered_map<string, multiset<string>> myMap;
	vector<string> result;
	void visit(string start){
		while(myMap[start].size()){
			string temp = *myMap[start].begin();
			myMap[start].erase(myMap[start].begin());
			visit(temp);
		}
		result.push_back(start);
	}
};


