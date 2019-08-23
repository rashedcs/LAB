#include <iostream>
#include<cstring>

#define PACKET_H
#define FRAME_H
#define maxPacketSize 50

using namespace std;

enum eventType {frameArrival,error,unknown};
typedef int seq_no;
enum frame_kind {data, ack, nak};


bool isFrameArrival= false;
bool isError=false;
bool isFrameAtPhyLayer = false;



class Packet
{
    public:
        char data[maxPacketSize];
};


class Frame
{
    public:
        Packet info;
        seq_no seqNo;
        seq_no ackNo;
        frame_kind kind;
}frameAtPhyLayer;;


void from_NL(Packet &p)
{
    cout<<"\nEnter data: ";
    cin.getline(p.data,maxPacketSize);
}

void from_PL(Frame &f)
{
    if(isFrameAtPhyLayer)
    {
      f = frameAtPhyLayer;
      isFrameAtPhyLayer = false;
    }
    else
        cout<<"Frame not at Physical Layer!\n";
}

void to_NL(Packet &p)
{
    cout<<"Data      : ";
    cout<<p.data<<endl;
}

void to_PL(Frame &f)
{
    frameAtPhyLayer = f;
    isFrameAtPhyLayer = true;
}

void wait_for_event(eventType &event)
{
    if(isFrameAtPhyLayer)
    {
        isFrameArrival = true;
        event = frameArrival;
    }
    else
    {
        isError = true;
        event = error;
    }
}

void receiver1();
void sender1()
{
    Frame s;
    Packet buffer;

    from_NL(buffer);
    s.info = buffer;
    to_PL(s);
}

void receiver1()
{
    Frame r;
    eventType event;

    wait_for_event(event);
    from_PL(r);
    to_NL(r.info);
}

int main()
{
    char ch;

    do
    {
        sender1();
        receiver1();

        cout<<"\nContinue(y/n): ";
        cin>>ch;
        cin.ignore();
    }
    while(ch=='y');

    return 0;
}
