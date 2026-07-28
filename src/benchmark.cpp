/////// main.cpp 
import A;
#import <iostream>
#import <vector>

#import <pxr/base/tf/notice.h>
#import <pxr/base/tf/weakBase.h>
#import <pxr/base/tf/instantiateType.h>

PXR_NAMESPACE_USING_DIRECTIVE
using namespace std;

class EditorDrawTopLevelNotice : public TfNotice
{
};

TF_INSTANTIATE_TYPE(EditorDrawTopLevelNotice, TfType::CONCRETE, TF_1_PARENT(TfNotice));

class BaseDrawer
{};

#define mkdrawer(i) \
    class TestDrawer##i                                                                     \
        : public BaseDrawer, public TfWeakBase                                                                     \
        , public TfRefBase                                                                      \
    {                                                                       \
    public:                                                                     \
        static TfRefPtr<TestDrawer##i> New()                                                                       \
        {                                                                       \
            return TfCreateRefPtr(new TestDrawer##i());                                                                        \
        }                                                                       \
                                                                            \
        TestDrawer##i()                                                                        \
        {                                                                       \
            TfWeakPtr<TestDrawer##i> me(this);                                                                     \
            _key = TfNotice::Register(me, &TestDrawer##i::DoDraw);                                                                     \
        }                                                                       \
                                                                            \
        void DoDraw(const EditorDrawTopLevelNotice& event)                                                                      \
        {                                                                       \
            _drawCount++;                                                                       \
        }                                                                       \
                                                                                \
        TfNotice::Key _key;                                                                     \
        int _drawCount = 0;                                                                     \
    };                                                                      \

#define initdrawer(i) drawers.push_back(new TestDrawer##i {});

/*
mkdrawer(0); mkdrawer(1); mkdrawer(2); mkdrawer(3); mkdrawer(4); mkdrawer(5); mkdrawer(6); mkdrawer(7); mkdrawer(8); mkdrawer(9);
mkdrawer(10); mkdrawer(11); mkdrawer(12); mkdrawer(13); mkdrawer(14); mkdrawer(15); mkdrawer(16); mkdrawer(17); mkdrawer(18); mkdrawer(19);
mkdrawer(20); mkdrawer(21); mkdrawer(22); mkdrawer(23); mkdrawer(24); mkdrawer(25); mkdrawer(26); mkdrawer(27); mkdrawer(28); mkdrawer(29);
mkdrawer(30); mkdrawer(31);mkdrawer(32); mkdrawer(33); mkdrawer(34); mkdrawer(35); mkdrawer(36); mkdrawer(37); mkdrawer(38); mkdrawer(39);
mkdrawer(40); mkdrawer(41); mkdrawer(42); mkdrawer(43); mkdrawer(44); mkdrawer(45); mkdrawer(46); mkdrawer(47); mkdrawer(48); mkdrawer(49);
mkdrawer(50); mkdrawer(51); mkdrawer(52); mkdrawer(53); mkdrawer(54); mkdrawer(55); mkdrawer(56); mkdrawer(57); mkdrawer(58); mkdrawer(59);
mkdrawer(60); mkdrawer(61); mkdrawer(62); mkdrawer(63); mkdrawer(64); mkdrawer(65); mkdrawer(66); mkdrawer(67); mkdrawer(68); mkdrawer(69);
mkdrawer(70); mkdrawer(71); mkdrawer(72); mkdrawer(73); mkdrawer(74); mkdrawer(75); mkdrawer(76); mkdrawer(77); mkdrawer(78); mkdrawer(79);
mkdrawer(80); mkdrawer(81); mkdrawer(82); mkdrawer(83); mkdrawer(84); mkdrawer(85); mkdrawer(86); mkdrawer(87); mkdrawer(88); mkdrawer(89);
mkdrawer(90); mkdrawer(91); mkdrawer(92); mkdrawer(93); mkdrawer(94); mkdrawer(95); mkdrawer(96); mkdrawer(97); mkdrawer(98); mkdrawer(99);
mkdrawer(100); mkdrawer(101); mkdrawer(102); mkdrawer(103); mkdrawer(104); mkdrawer(105); mkdrawer(106); mkdrawer(107); mkdrawer(108); mkdrawer(109);
mkdrawer(110); mkdrawer(111); mkdrawer(112); mkdrawer(113); mkdrawer(114); mkdrawer(115); mkdrawer(116); mkdrawer(117); mkdrawer(118); mkdrawer(119);
mkdrawer(120); mkdrawer(121); mkdrawer(122); mkdrawer(123); mkdrawer(124); mkdrawer(125); mkdrawer(126); mkdrawer(127);*/

int main()
{
    /*
    Viewport vp;
    Editor ed(&vp);
    ed.DoStuff();

    vector<BaseDrawer*> drawers;

    initdrawer(0); initdrawer(1); initdrawer(2); initdrawer(3); initdrawer(4); initdrawer(5); initdrawer(6); initdrawer(7); initdrawer(8); initdrawer(9);
    initdrawer(10); initdrawer(11); initdrawer(12); initdrawer(13); initdrawer(14); initdrawer(15); initdrawer(16); initdrawer(17); initdrawer(18); initdrawer(19);
    initdrawer(20); initdrawer(21); initdrawer(22); initdrawer(23); initdrawer(24); initdrawer(25); initdrawer(26); initdrawer(27); initdrawer(28); initdrawer(29);
    initdrawer(30); initdrawer(31); initdrawer(32); initdrawer(33); initdrawer(34); initdrawer(35); initdrawer(36); initdrawer(37); initdrawer(38); initdrawer(39);
    initdrawer(40); initdrawer(41); initdrawer(42); initdrawer(43); initdrawer(44); initdrawer(45); initdrawer(46); initdrawer(47); initdrawer(48); initdrawer(49);
    initdrawer(50); initdrawer(51); initdrawer(52); initdrawer(53); initdrawer(54); initdrawer(55); initdrawer(56); initdrawer(57); initdrawer(58); initdrawer(59);
    initdrawer(60); initdrawer(61); initdrawer(62); initdrawer(63); initdrawer(64); initdrawer(65); initdrawer(66); initdrawer(67); initdrawer(68); initdrawer(69);
    initdrawer(70); initdrawer(71); initdrawer(72); initdrawer(73); initdrawer(74); initdrawer(75); initdrawer(76); initdrawer(77); initdrawer(78); initdrawer(79);
    initdrawer(80); initdrawer(81); initdrawer(82); initdrawer(83); initdrawer(84); initdrawer(85); initdrawer(86); initdrawer(87); initdrawer(88); initdrawer(89);
    initdrawer(90); initdrawer(91); initdrawer(92); initdrawer(93); initdrawer(94); initdrawer(95); initdrawer(96); initdrawer(97); initdrawer(98); initdrawer(99);
    initdrawer(100); initdrawer(101); initdrawer(102); initdrawer(103); initdrawer(104); initdrawer(105); initdrawer(106); initdrawer(107); initdrawer(108); initdrawer(109);
    initdrawer(110); initdrawer(111); initdrawer(112); initdrawer(113); initdrawer(114); initdrawer(115); initdrawer(116); initdrawer(117); initdrawer(118); initdrawer(119);
    initdrawer(120); initdrawer(121); initdrawer(122); initdrawer(123); initdrawer(124); initdrawer(125); initdrawer(126); initdrawer(127);

    for(int i = 0; i < 10'000'000; i++)
    {
        EditorDrawTopLevelNotice{}.Send();
    }*/

    float time = 51.01f;
    float length = 1.0f;

    float x = std::fmodf(time, length);
    float y = std::remainder(time, length);
    std::cout << "mod: " << x << "\n";
    std::cout << "remainder: " << y << "\n";

    return 0;
}