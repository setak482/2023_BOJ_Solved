#include <bits/stdc++.h>
#define MAX_SIZE 102
using namespace std;
struct loc{int x, y;};
unordered_map<char, loc> _dir = {
    {'R', {1, 0}},
    {'D', {0, 1}},
    {'L', {-1, 0}},
    {'U', {0, -1}}
};
char _map[MAX_SIZE][MAX_SIZE];
string _mapAcc[MAX_SIZE][MAX_SIZE];
int xBorder, yBorder, passedTurns;
string move_string;
class Item{
public:
    char type;
    int value;
    Item() : type('?'), value(INT_MAX){}
    Item(char c, int n) : type(c), value(n){}
};
Item _mapItem[MAX_SIZE][MAX_SIZE];
class Player{
public:
    unordered_map<string, bool> acc_check;
    Item *weapon, *armor;
    int level, passed_turns,
        max_hp, cur_hp,
        base_atk, weapon_atk,
        base_def, armor_def,
        cur_xp,
        equiped_acc = 0,
        x, y, init_x, init_y;
    Player(){}
    Player(int y, int x){
        acc_check = {
            {"HR", false},
            {"RE", false},
            {"CO", false},
            {"EX", false},
            {"DX", false},
            {"HU", false},
            {"CU", false}
        };
        level = 1;
        max_hp = cur_hp = 20;
        base_atk = 2; weapon_atk = 0;
        base_def = 2; armor_def = 0;
        cur_xp = 0;
        passed_turns = 0;
        armor = nullptr; weapon = nullptr;
        this->x = x;
        this->y = y;
        init_x = x;
        init_y = y;
    }
};
class Monster{
public:
    string name;
    int atk, def, hp, max_hp, reward_xp;
    Monster() : name("NULL"), atk(0), def(0), hp(0), max_hp(0), reward_xp(0){}
    Monster(string n, int a, int d, int h, int x){
        name = n; atk = a; def = d; hp = h; reward_xp = x;
        max_hp = hp;
    }
};
Monster _mapMonster[MAX_SIZE][MAX_SIZE];
Player hero;
void ending_text(){
    for(int i = 1; i <= yBorder; i++){
        for(int j = 1; j <= xBorder; j++)
            cout << _map[i][j];
        cout << '\n';
    }
    cout << "Passed Turns : " << hero.passed_turns << '\n' <<
            "LV : " << hero.level << '\n' <<
            "HP : " << max(0, hero.cur_hp) << '/' << hero.max_hp << '\n' <<
            "ATT : " << hero.base_atk << '+' << hero.weapon_atk << '\n' <<
            "DEF : " << hero.base_def << '+' << hero.armor_def << '\n' <<
            "EXP : " << hero.cur_xp << '/' << hero.level*5 << '\n';
}
bool rebirth_flag = false;                      // 부활 시그널
bool death_check(string offender){
    if(hero.acc_check["RE"] && hero.cur_hp <= 0){
        hero.cur_hp = hero.max_hp;
        hero.acc_check["RE"] = false;
        hero.equiped_acc--;
        hero.x = hero.init_x;
        hero.y = hero.init_y;
        rebirth_flag = true;
        return false;
    }
    else if(hero.cur_hp <= 0){
        ending_text();
        cout << "YOU HAVE BEEN KILLED BY " << offender << "..";
        return true;
    }
    return false;
}
void levelup_check(){
    if(hero.cur_xp >= hero.level*5){
        hero.max_hp += 5;
        hero.cur_hp = hero.max_hp;
        hero.base_atk += 2;
        hero.base_def += 2;
        hero.level++;
        hero.cur_xp = 0;
    }
}
void move(){
    for(char& cur_dir : move_string){
        hero.passed_turns++;
        int dx = hero.x + _dir[cur_dir].x;
        int dy = hero.y + _dir[cur_dir].y;
        if(_map[dy][dx] == '#' || dx < 1 || dy < 1 || dx > xBorder || dy > yBorder){    // 벽에 부딪혔을 때는 제자리로
            dx = hero.x;
            dy = hero.y;
        };                           // 경로에 벽이 있는 경우 움직이지 않는다.
        if(_map[dy][dx] == 'B'){                                    // 현재 위치에 아이템 상자가 있을 경우
            Item cur_item = _mapItem[dy][dx];
            string cur_acc = _mapAcc[dy][dx];
            if(cur_item.type == 'W'){                               // 아이템이 무기일 때
                hero.weapon = &cur_item;
                hero.weapon_atk = hero.weapon->value;
            }
            else if(cur_item.type == 'A'){                          // 아이템이 방어구일 때
                hero.armor = &cur_item;
                hero.armor_def = hero.armor->value;
            }
            else{                                                   // 아이템이 장신구일 때
                if(hero.equiped_acc <= 4){
                    hero.equiped_acc++;
                    hero.acc_check[cur_acc] = true;
                }
            }
            _map[dy][dx] = '.';
        }

        else if(_map[dy][dx] == '^'){                               // 가시함정 밟았을 때
            if(hero.acc_check["DX"]) hero.cur_hp--;
            else hero.cur_hp -= 5;
            if(death_check("SPIKE TRAP")) return;
        }

        else if(_map[dy][dx] == '&' || _map[dy][dx] == 'M'){        // 몬스터 & 보스 몬스터 배틀
            int turn_step = 0;
            while(true){
                turn_step++;
                if(_map[dy][dx] == 'M' && hero.acc_check["HU"] && turn_step==1){
                    hero.cur_hp = hero.max_hp;
                }
                // 플레이어 선공
                if(hero.acc_check["CO"] && hero.acc_check["DX"] && turn_step==1){       // 첫 턴, CO와 DX를 가지고 있을 때 공격력 3배
                    _mapMonster[dy][dx].hp -= max(1, (hero.base_atk + hero.weapon_atk)*3-_mapMonster[dy][dx].def);
                }
                else if(hero.acc_check["CO"] && turn_step==1){
                    _mapMonster[dy][dx].hp -= max(1, (hero.base_atk + hero.weapon_atk)*2-_mapMonster[dy][dx].def);
                }
                else{
                    _mapMonster[dy][dx].hp -= max(1, (hero.base_atk + hero.weapon_atk)-_mapMonster[dy][dx].def);
                }

                if(_mapMonster[dy][dx].hp <= 0) break;
                

                // 적 몬스터 후공
                if(!(_map[dy][dx] == 'M' && hero.acc_check["HU"] && turn_step==1)) hero.cur_hp -= max(1, _mapMonster[dy][dx].atk-(hero.base_def+hero.armor_def));
                if(death_check(_mapMonster[dy][dx].name)) return;
                if(rebirth_flag) break;
            }
            // 승리 시,
            if(!rebirth_flag){      // 부활 시 제외
                if(hero.acc_check["HR"]) hero.cur_hp = min(hero.max_hp, hero.cur_hp+3);
                if(hero.acc_check["EX"]) hero.cur_xp += floor(_mapMonster[dy][dx].reward_xp*1.2);
                else hero.cur_xp += _mapMonster[dy][dx].reward_xp;
                
                levelup_check();

                if(_map[dy][dx] == 'M'){        // 보스일 경우
                    _map[dy][dx] = '@';
                    ending_text();
                    cout << "YOU WIN!";
                    return;
                }
                _map[dy][dx] = '.';
            }
        }
        if(rebirth_flag){
            hero.x = hero.init_x;
            hero.y = hero.init_y;
            if(_map[dy][dx] == '&' || _map[dy][dx] == 'M')
                _mapMonster[dy][dx].hp = _mapMonster[dy][dx].max_hp;
            rebirth_flag = false;
        }
        else{
            hero.x = dx;
            hero.y = dy;
        }
        
    }
    _map[hero.y][hero.x] = '@';
    ending_text();
    cout << "Press any key to continue.";
}
void input(){
    int monster = 0, itembox = 0;
    cin >> yBorder >> xBorder;
    for(int i = 1; i <= yBorder; i++){
        for(int j = 1; j <= xBorder; j++){
            char c; cin >> c;
            if(c == '&' || c == 'M') monster++;
            else if(c == 'B') itembox++;
            if(c=='@'){
                hero = Player(i, j);
                _map[i][j] = '.';
            }
            else _map[i][j] = c;
        }
    }
    cin >> move_string;
    for(int i = 0; i < monster; i++){
        string _name;
        int x, y, _atk, _def, _hp, _xp;
        cin >> y >> x >> _name >> _atk >> _def >> _hp >> _xp;
        _mapMonster[y][x] = Monster(_name, _atk, _def, _hp, _xp);
    }
    for(int i = 0; i < itembox; i++){
        int x, y;
        char type;
        cin >> y >> x >> type;
        if(type == 'O'){
            string acc;
            cin >> acc;
            _mapAcc[y][x] = acc;
        }
        else{
            int value; cin >> value;
            _mapItem[y][x] = Item(type, value);
        }
    }
}
int main(){
    input();
    move();
}