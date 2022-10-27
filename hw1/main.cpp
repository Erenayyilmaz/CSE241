#include "utils.h"
using namespace std;

int main()
{
	vector< vector <char> > merged_map
	{
		{'0','0','0','0'},
		{'0','0','0','0'},
		{'0','0','0','0'},
		{'0','0','0','0'}
	};
	vector< vector <char> > merged_temp_map
	{
		{'0','0','0','0'},
		{'0','0','0','0'},
		{'0','0','0','0'},
		{'0','0','0','0'}
	};
	vector <Tetromino> arr;

	//Tetromino a;
	  //e_typ k;
	  //k = e_typ::j;
	  //Tetromino	a(k);
	//arr.push_back(a);
	get_info(arr);
	cout << "bura geld aaaaa" << endl ;
	//merged_map = a.get_coll_map();
	merged_map = arr[0].get_coll_map();
	cout << "bura geld bb" << endl ;
	merged_temp_map = merge_coll_maps(arr[0],merged_map);//arr[0] ile erişemiyorum..
//	merged_temp_map = merge_coll_maps(a,merged_map);
	if (!merged_temp_map.size())
		cout<<"zize: 0";
	cout << "bura geld ddddd" << endl ;
	for (int i = 0; i < 4; i++)
	{
		cout << "for 1ici girdi"<<endl;
		for (int k = 0; k< 8; i++)
		{
			cout << "for ici girdi"<<endl;
			cout << merged_temp_map[i][k];
			cout << "merge map sonu"<<endl;
		}
		cout << endl;
	}
	
	for (int i = 1; i < arr.size(); i++)
	{
		//int	best_surface_coll_counter = most_surf(merged_map);
		vector< vector <char> > prev_mer_map;
		prev_mer_map = merged_map;
		for (int j = 0; j < 4; j++)//4 rotatoion
		{
			//shift
			shift_coll_map(merged_map, i);
			if (most_surf(merged_map) > most_surf(prev_mer_map))
				prev_mer_map = merged_map;
		}
		
	}
	
	return (0);
}

