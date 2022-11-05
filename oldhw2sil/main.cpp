#include "utils.h"
using namespace std;

int main(void)
{
	vector <Tetromino> arr;
	//arr.resize(2);
	/*vector< vector <char> > merged_map
	{
		{'0','0','0','0'},
		{'0','0','0','0'},
		{'0','0','0','0'},
		{'0','0','0','0'}
	};*/
	vector< vector <char> > merged_map;
	merged_map.resize(4);
	for (int i = 0; i < 4; i++)
		merged_map[i].resize(200);	
	vector< vector <char> > merged_temp_map;
	merged_temp_map.resize(4);
	for (int i = 0; i < 4; i++)
		merged_temp_map[i].resize(200);	
	/*vector< vector <char> > merged_temp_map
	{
		{'0','0','0','0'},
		{'0','0','0','0'},
		{'0','0','0','0'},
		{'0','0','0','0'}
	};*/

	//Tetromino a;
	  //e_typ k;
	  //k = e_typ::j;
	  //Tetromino	a(k);
	//arr.push_back(a);
	int tet_num = get_info(arr);		
	for (int i = 0;i < tet_num;i++)
	{
		//cout << "asdsad";
		//arr[i].print();
		// cout << "map printlendi";
		// cout << endl;
		//arr[i].print();
		// cout << endl;
		//cout << a.get_ty();
	}					//Getting input from user
	//cout << "bura geld aaaaa" << endl ;
	//arr[0].print();
	//print_map(arr[0].get_map());
	//cout << endl ;
	
	merged_map = merge_coll_maps(arr[0], merged_map);
	cout << endl;
	print_map(merged_map);
	cout << "second" << endl;

	merged_map = merge_coll_maps(arr[1], merged_map);
	cout << endl;
	print_map(merged_map);
	//Tetromino a;
	//a = arr[0];
//	merged_map = arr[0].get_coll_map();
	//cout << endl;
	//	print_map(merged_map);
	//cout <<endl;
	//merged_map = a.get_coll_map();
	//cout << "bura geld bb" << endl ;
//	merged_map = merge_coll_maps(arr[0],merged_map);//arr[0] ile erişemiyorum..
//	merged_temp_map = merge_coll_maps(a,merged_map);
	if (!merged_temp_map.size())					 // If map is NULL there must be problem
		cout<<"zize: 0";
	//cout << "bura geld ddddd" << endl ;
	for (int i = 0; i < 4; i++)
	{
	//	cout << "for 1ici girdi"<<endl;
		for (int k = 0; k< 4; k++)
		{
	//		cout << "for ici girdi"<<endl;
			cout << merged_temp_map[i][k];
	//		cout << "merge map sonu"<<endl;
		}
		cout << endl;
	}
	//cout << "safe"<<endl;
	//print_map(merged_temp_map);
	//cout <<endl;
	for (int i = 1; i < arr.size(); i++)// All tetrominos
	{
		
		//int	best_surface_coll_counter = most_surf(merged_map);
		vector< vector <char> > prev_mer_map;
		prev_mer_map = merged_map;
		for (int j = 0; j < 4; j++)//4 rotation
		{													/*FOR ALL ROTATIONS OF ALL TETROMINOS WILL CONTROL IN HERE.
													   BEST SURFACE COLLISION STATE WILL STAY AND STORE THEN IT WILL PRINTED*/

														  /* MY ALGOTITHM WILL TRY FIT FOR ALL 4 ROTATIONS OF EACH TETROS */
											  /*THEY WILL BE SHIFTED FROM RIGHT 1 BY 1 AND PROGRAM WILL STORE BEST COLLISION SITUTATION*/
											  			   /*AND RETURN PREV_SITUATION THAT IS BEFORE COLLISION SITUATION*/
			//shift
			//cout << "MERGED MAP:	"<< endl;
			//print_map(merged_map);
			//cout << endl;
			//merged_temp_map = shift_coll_map(merged_map, i);
			//cout << endl;
			//print_map(merged_temp_map);
			//if (most_surf(merged_map) > most_surf(prev_mer_map))
			//	prev_mer_map = merged_map;
			//merged_map = merge_coll_maps(arr[i], merged_map);
		}
		
	}
	
	return (0);
}

