#include <iostream>
using namespace std;

// Adaptee
class XMLData {
    string xmlData;
    public:
    XMLData(string pXmlData) {
        xmlData = pXmlData;
    }
    string getXMLData() {
        return xmlData;
    }
};

// Target
class DataAnalyticsTool {
    string jsonData;
    public:
    DataAnalyticsTool() {}
    DataAnalyticsTool(string pJsonData) {
        jsonData = pJsonData;
    }
    virtual void analyseData() {
        cout<<"Analysing Data "<<jsonData<<'\n';
    }
};

class Adapter: public DataAnalyticsTool {
    XMLData* xmlData;
    public:
    Adapter(XMLData* pXMLData){
        xmlData = pXMLData;
    }

    void analyseData() {
        cout<<"Converting XML Data "<<xmlData->getXMLData()<<" to JSON Data"<<'\n';
        cout<<"Analysing the converted JSON Data"<<'\n';
    }
};

class Client {
    public:
    void ProcessData(DataAnalyticsTool* tool) {
        tool->analyseData();
    }
};

int main() {
    XMLData* xmlData = new XMLData("Sample XML Data");
    DataAnalyticsTool* tool = new Adapter(xmlData);
    Client* client = new Client;
    client->ProcessData(tool);

    return 0;
}
