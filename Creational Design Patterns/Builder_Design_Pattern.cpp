#include <iostream>
using namespace std;

// Product Class
class Desktop {
    string monitor;
    string keyboard;
    string mouse;
    string speaker;
    string ram;
    string processor;
    string mother_board;

    public:
    void setMonitor(string p_monitor) {
        monitor = p_monitor;
    }
    void setKeyboard(string p_keyboard) {
        keyboard = p_keyboard;
    }
    void setMouse(string p_mouse) {
        mouse = p_mouse;
    }
    void setSpeaker(string p_speaker) {
        speaker = p_speaker;
    }
    void setRam(string p_ram) {
        ram = p_ram;
    }
    void setProcessor(string p_processor) {
        processor = p_processor;
    }
    void setMotherBoard(string p_mother_board) {
        mother_board = p_mother_board;
    }

    void showSpecifications() {
        cout<< "-----------------------------------------------------------------"<<'\n';
        cout<<"Monitor: "<<monitor<<'\n';
        cout<<"Keyboard: "<<keyboard<<'\n';
        cout<<"Mouse: "<<mouse<<'\n';
        cout<<"Speaker: "<<speaker<<'\n';
        cout<<"Ram: "<<ram<<'\n';
        cout<<"Processor: "<<processor<<'\n';
        cout<<"MotherBoard: "<<mother_board<<'\n';
    }
};

// Builder Class
// This has the product as a component
class DesktopBuilder {
    protected:
        Desktop* desktop;
    public:
        DesktopBuilder() {
            desktop = new Desktop();
        }

        virtual void buildMonitor() = 0;
        virtual void buildKeyboard() = 0;
        virtual void buildMouse() = 0;
        virtual void buildSpeaker() = 0;
        virtual void buildRam() = 0;
        virtual void buildProcessor() = 0;
        virtual void buildMotherBoard() = 0;
        virtual Desktop* getDesktop() {
            return desktop;
        }
};

// Product Type 1 Builder
class HPDesktopBuilder: public DesktopBuilder {
    void buildMonitor() {
        desktop->setMonitor("HP Monitor");
    }
    void buildKeyboard() {
        desktop->setKeyboard("HP Keyboard");
    }
    void buildMouse() {
        desktop->setMouse("HP Mouse");
    }
    void buildSpeaker() {
        desktop->setSpeaker("HP Speaker");
    }
    void buildRam() {
        desktop->setRam("HP Ram");
    }
    void buildProcessor() {
        desktop->setProcessor("HP Processor");
    }
    void buildMotherBoard() {
        desktop->setMotherBoard("HP MotherBoard");
    }
};

// Product Type 2 Builder
class DellDesktopBuilder: public DesktopBuilder {
    void buildMonitor() {
        desktop->setMonitor("Dell Monitor");
    }
    void buildKeyboard() {
        desktop->setKeyboard("Dell Keyboard");
    }
    void buildMouse() {
        desktop->setMouse("Dell Mouse");
    }
    void buildSpeaker() {
        desktop->setSpeaker("Dell Speaker");
    }
    void buildRam() {
        desktop->setRam("Dell Ram");
    }
    void buildProcessor() {
        desktop->setProcessor("Dell Processor");
    }
    void buildMotherBoard() {
        desktop->setMotherBoard("Dell MotherBoard");
    }
};

// Product Director
// This has a builder as a component
class DesktopDirector {
    private:
        DesktopBuilder* desktop_builder;
    public:
        DesktopDirector(DesktopBuilder* p_desktop_builder) {
            desktop_builder = p_desktop_builder;
        }

        Desktop* buildDesktop() {
            desktop_builder->buildMonitor();
            desktop_builder->buildKeyboard();
            desktop_builder->buildMouse();
            desktop_builder->buildMotherBoard();
            desktop_builder->buildSpeaker();
            desktop_builder->buildRam();
            desktop_builder->buildProcessor();
            desktop_builder->buildMotherBoard();
            return desktop_builder->getDesktop();
        }
};

int32_t main() {
    DesktopBuilder* hp_desktop_builder = new HPDesktopBuilder();
    DesktopBuilder* dell_desktop_builder = new DellDesktopBuilder();

    DesktopDirector* hp_desktop_director = new DesktopDirector(hp_desktop_builder);
    DesktopDirector* dell_desktop_director = new DesktopDirector(dell_desktop_builder);

    Desktop* hp_desktop = hp_desktop_director->buildDesktop();
    Desktop* dell_desktop = dell_desktop_director->buildDesktop();

    hp_desktop->showSpecifications();
    dell_desktop->showSpecifications();
    return 0;
}
