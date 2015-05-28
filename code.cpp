//
//	Бесконечное, циклическое отображение текстового файла.
//	Сделано специально для просмотра текстового изображения обнажённой 
//	девушки очень похожей на мою жену :)
//

#include "code.h"

//------------------------------------------------------------------------------

int msleep(unsigned long milisec)  
{  
    struct timespec req={0};
    time_t sec=(int)(milisec/1000);
    milisec=milisec-(sec*1000);
    req.tv_sec=sec;
    req.tv_nsec=milisec*1000000L;

    while(nanosleep(&req,&req)==-1)  
        continue;  

    return 1;  
}

//------------------------------------------------------------------------------

vector<string> read_file(const string& filename)
{
	vector<string> v;
	ifstream ist(filename.c_str());
	if (!ist) error ("Don`t read this file: "+filename);
	string str;
	while (getline(ist,str)) {
		if (ist.eof()) break;
		v.push_back(str);
	}
	return v;
}

//------------------------------------------------------------------------------

void print (const vector<string>& p, int delay)
{
	while (true)
		for (int i=0; i<p.size(); i++) {
			cout << p[i] << endl;
			msleep(10*delay);
		}
}

//------------------------------------------------------------------------------

int main()
try {
	cout << "Input filename: ";
	string filename;
	cin >> filename;
	cout << "Delay: ";
	int d=0;
	cin >> d;
	vector<string> p = read_file(filename);
	print(p,d);
    return 0;
}
catch (exception& e) {
    cerr << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "Oops... exception...\n";
    return 2;
}

/*
//------------------------------------------------------------------------------
_______________8888ooo8888888888888888888888888
_____________8888oooooo888888888888888888888888888 8
____________88oooooooo888ooo8888888888888888888888 888
__________88888888oooo8ooooooooooo8888888888888888 8888
________888_8oo888888oooooooooooooooooo88888888888 888
___________88oooo88888888oooomoooooooooo8888888888 8 8
_________888888888888888888oMooooooooooo8888888888 888
________88888888888888888888ooooooooooooM888888888 88888
________8888888888888888888888oooooooooM8888888888 888888
_________8888888888888888888888oooooooM88888888888 8888888
________8888888888888888oo88888ooooooM888888888888 88888888
______88888888888888888ooo88888oooooM8888888888888 88 8888
_____88888888888888888ooo88888ooooMoo;o*M*o;888888 888 88
____88888888888888888ooo8888oooooMooooooooooo88888 888 8
___88888888888888888oooo88ooooooMo;ooooooooooo8888 88888
__8888888888888888888ooo8ooooooMooaAaooooooooM8888 888888_______
__88___8888888888oo88oooo8ooooMooooooooooooo888888 888888888_8888
_88__88888888888ooo8oooooooooMoooooooooo;oo88o8888 8888888888888
_8__8888888888888oooooooooooMoo"@@@@@"oooo8w888888 8888888888
__88888888888o888ooooooooooMooooo"@a@"oooooM8i8888 88888888888
_8888888888oooo88oooooooooM88oooooooooooooM88z8888 8888888888888
8888888888ooooo8oooooooooM88888oooooooooMM888!8888 88888888888888
888888888ooooo8oooooooooM8888888MAmmmAMVMM888*8888 8888___88888888
888888_MoooooooooooooooM888888888oooooooMM88888888 888888___8888888
8888___MooooooooooooooM88888888888ooooooMM88888888 8888888____88888
_888___MoooooooooooooM8888888888888MooooomM8888888 88888888____8888
__888__MooooooooooooM8888o888888888888oooomooMm888 88_888888___8888
___88__Moooooooooooo8888o88888888888888888ooooooMm 8___88888___888
___88__Moooooooooo8888Moo88888oo888888888888oooooo oMm88888____88
___8___MMoooooooo8888Mooo8888ooooo888888888888oooo ooooMm8_____8
_______8Mooooooo8888Mooooo888ooooooo88ooo8888888oo ooooooMm____8
______88MMooooo8888Mooooooo88oooooooo8ooooo888888o ooMoooooM
_____8888Mooooo888MMoooooooo8oooooooooooMoooo8888o oooMooooM
____88888Mooooo88oMoooooooooo8oooooooooooMooo8888o oooooMooM
___88_888MMooo888oMoooooooooooooooooooooooMo8888oo oooooooMo
___8_88888Mooo88ooMoooooooooooooooooooooooMMo88ooo oooooooooM
_____88888Mooo88ooMoooooooooo*88*ooooooooooMo88ooo oooooooooooM
____888888Mooo88ooMooooooooo88@@88ooooooooMoo88ooo oooooooooooM
____888888MMoo88ooMMoooooooo88@@88oooooooMooo8oooo ooooooooooo*8
____88888__Mooo8ooMMooooooooo*88*ooooooooooMoooooo ooooooooooo88@@
____8888___MMooooooMMoooooooooooooooooooooMMoooooo ooooooooooo88@@
_____888____MoooooooMMoooooooooooooooooooMMooMoooo ooooooooooooo*8
_____888____MMoooooooMMMooooooooooooooooMMoooMMooo ooooooooooooM
______88_____MooooooooMMMMoooooooooooMMMMoooooMMoo ooooooooooMM
_______88____MMoooooooooMMMMMMMMMMMMMooooooooMMMoo ooooooMM
________88____MMooooooooooooMMMMMMMooooooooooooMMM MMMMMMM
_________88___8MMooooooooooooooooooooooooooooooooo oMMMMMM
__________8___88MMooooooooooooooooooooooMoooMooooo oooMM
______________888MMooooooooooooooooooMMooooooMMooo oooMM
_____________88888MMoooooooooooooooMMMooooooomMooo ooMM
_____________888888MMoooooooooooooMMMoooooooooMMMo ooM
____________88888888MMoooooooooooMMMoooooooooooMMo ooM
___________88_8888888MoooooooooMMMooooooooooooooMo ooM
___________8__888888_MoooooooMMoooooooooooooooooMo ooMo
______________888888_MooooooMoooooooooooooooooooMo ooMM
_____________888888__MoooooMoooooooooooooooooooooo ooMoM
_____________888888__MoooooMooooooooo@oooooooooooo ooMooM
_____________88888___Moooooooooooooo@@oooooooooooo oooMooM
____________88888___Moooooooooooooo@@@oooooooooooo ooooMooM
___________88888___Mooooooooooooooo@@ooooooooooooo oooooMooM
__________88888___Mooooomoooooooooo@ooooooooooMmoo oooooMoooM
__________8888___MoooooMoooooooooooooooooooooooMMo ooooooMoooM
_________8888___MoooooMoooooooooooooooooooooooMMMo oooooooMoooM
________888____MoooooMmooooooooooooooooooooooMMMoo oooooooMooooM
______8888____MMooooMmoooooooooooooooooooooMMMMooo oooooomoomoooM
_____888______MoooooMooooooooooooooooooooMMMoooooo ooooooMoommoooM
__8888_______MMoooooooooooooooooooooooooMMoooooooo ooooomMooMMoooMo
_____________MoooooooooooooooooooooooooMoooooooooo ooooomMooMMoooMm
____________MMoooooomooooooooooooooooooooooooooooo ooooooMooMMoooMM
____________MooooooooMoooooooooooooooooooooooooooo oooooooMooMoooMM
___________MMoooooooooMoooooooooooooMooooooooooooo ooooooooMoMoooMM
___________MoooooooooooM88oooooooooMoooooooooooooo oooooooooMMooMMM
___________Moooooooooooo8888888888Mooooooooooooooo oooooooooMMooMM
___________Mooooooooooooo88888888Moooooooooooooooo oooooooooMooMM
___________Moooooooooooooo888888Mooooooooooooooooo ooooooooMooMM
___________Mooooooooooooooo88888Mooooooooooooooooo ooooooooMoMM
___________Mooooooooooooooooo88Moooooooooooooooooo ooooooooMMM
___________MoooooooooooooooooooMoooooooooooooooooo ooooooooMMM
___________MMoooooooooooooooooMooooooooooooooooooo oooooooMMM
____________MoooooooooooooooooMooooooooooooooooooo oooooooMMM
____________MMoooooooooooooooMoooooooooooooooooooo ooooooMMM
_____________MoooooooooooooooMoooooooooooooooooooo oooooMMM
_____________MMoooooooooooooMooooooooooooooooooooo ooooMMM
______________MoooooooooooooMooooooooooooooooooooo oooMMM
______________MMoooooooooooMoooooooooooooooooooooo ooMMM
_______________MoooooooooooMoooooooooooooooooooooo oMMM
_______________MMoooooooooMooooooooooooooooooooooo MMM
________________MoooooooooMooooooooooooooooooooooM MM
________________MMoooooooMooooooooooooooooooooooMM M
_________________MMooooooMoooooooooooooooooooooMMM
_________________MMoooooMoooooooooooooooooooooMMM
__________________MMooooMooooooooooooooooooooMMM
__________________MMoooMooooooooooooooooooooMMM
___________________MMooMoooooooooooooooooooMMM
___________________MMoMoooooooooooooooooooMMM
____________________MMMooooooooooooooooooMMM
____________________MMooooooooooooooooooMMM
_____________________MoooooooooooooooooMMM
____________________MMooooooooooooooooMMM
____________________MMoooooooooooooooMMM
____________________MMooooMoooooooooMMMo
____________________mMMooooMMoooooooMMMM
_____________________MMMoooooooooooMMMoM
_____________________mMMoooMoooooooMoMoM
______________________MMooMMMMoooooooMoM
______________________MMooMMMooooooooMoM
______________________mMMooMMooooooooMoM
_______________________MMooMMoooooooooMoM
_______________________MMooMMooooooooooMom
_______________________MMoooMoooooooooooMM
_______________________MMMoooooooooooooooMo
_______________________MMMoooooooooooooooMo
_______________________MMMooooooooooooooooM
_______________________MMMooooooooooooooooM
_______________________MMMooooooooooooooooMm
________________________MMooooooooooooooooMM
________________________MMMoooooooooooooooMM
________________________MMMoooooooooooooooMM
________________________MMMoooooooooooooooMM
________________________MMMoooooooooooooooMM
_________________________MMooooooooooooooMMM
_________________________MMMoooooooooooooMM
_________________________MMMoooooooooooooMM
_________________________MMMooooooooooooMM
__________________________MMooooooooooooMM
__________________________MMooooooooooooMM
__________________________MMoooooooooooMM
__________________________MMMooooooooooMM
__________________________MMMooooooooooMM
___________________________MMoooooooooMM
___________________________MMMooooooooMM
___________________________MMMooooooooMM
____________________________MMooooooooMM
____________________________MMMooooooMM
____________________________MMMooooooMM
_____________________________MMooooooMM
_____________________________MMooooooMM
______________________________MMoooooMM
______________________________MMoooooMMo
______________________________MMoooooMoM
______________________________MMoooooMoM
______________________________oMooooooMo
_____________________________MoMoooooooM
____________________________MoooMooooooM
___________________________MooooMooooooM
__________________________MoooooMoooooooM
_________________________MooooooMMoooooooM
_________________________MoooooooMooooooooM
_________________________M;o;ooooMoooooooooM
_________________________Momo;oooMooooooooooM
_________________________MMomomooMoooooooo;oM
__________________________MMomooMMooooooo;o;M
___________________________MMooMMMoooooo;omoM
___________________________MMMM_MMoooomomoMM
__________________________________MMoooomoMM
___________________________________MMooooMM
____________________________________MMooMM
__________________
*/
