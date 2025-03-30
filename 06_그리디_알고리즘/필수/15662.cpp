// 15662: ��Ϲ���2

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> li; //��Ϲ��� ���� ����
vector<pair<int, int>> stack; //ȸ�� ���(��Ϲ��� ��ȣ, ����) ���� ����
vector<int> visited; //�̹� ȸ���ߴ��� Ȯ���ϱ� ���� ����

void check_rotation(int current_num, int current_dir) //��Ϲ����� ȸ���ϴ��� üũ�ϴ� �Լ�
{
    if (current_num - 1 >= 0 && visited[current_num - 1] == 0) //���ʿ� ��Ϲ����� �ְ� ���� Ȯ������ ���� ���
    {
        if (li[current_num][6] != li[current_num - 1][2])
        { // �´�� �ִ� ���� ���� �ٸ� ������ üũ
            stack.push_back(make_pair(current_num - 1, current_dir * -1)); //�ݴ�������� ȸ��
            visited[current_num - 1] = 1; //Ȯ�� ó��
            check_rotation(current_num - 1, current_dir * -1); //�������� �̵�
        }
    }
    if (current_num + 1 < li.size() && visited[current_num + 1] == 0) //�����ʿ� ��Ϲ����� �ְ� ���� Ȯ������ ���� ���
    {
        if (li[current_num][2] != li[current_num + 1][6])
        { // �´�� �ִ� ���� ���� �ٸ� ������ üũ
            stack.push_back(make_pair(current_num + 1, current_dir * -1));//�ݴ�������� ȸ��
            visited[current_num + 1] = 1; //Ȯ�� ó��
            check_rotation(current_num + 1, current_dir * -1); //���������� �̵�
        }
    }
}

int main()
{
    int t;
    int k;

    cin >> t; // ��Ϲ����� ���� T �Է�

    li.resize(t); // ��Ϲ��� ������ŭ resize
    for (int i = 0; i < t; ++i)
        cin >> li[i]; // ��Ϲ��� ���� �Է�

    cin >> k; // ȸ�� Ƚ�� K �Է�
    for (int i = 0; i < k; ++i)
    { // k�� ���鼭 ȸ���� �� �ִ����� ���� üũ
        int num, direction; 
        cin >> num >> direction; // ���� �Է� (1�̸� �ð� ����, -1�̸� �ݽð� ����)
        stack.clear(); //ȸ�� ���� �ʱ�ȭ
        stack.push_back(make_pair(num - 1, direction)); //ȸ�� ���
        visited.assign(t, 0); // t����ŭ 0�� �ʱ�ȭ
        visited[num - 1] = 1; //ȸ���ߴٰ� ó����
        check_rotation(num - 1, direction); //���� ��� ȸ���ϴ��� Ȯ��

        while (!stack.empty()) //ȸ�� ����� �ִ� ���� ���
        {
            pair<int, int> top = stack.back(); //���ÿ��� ������ ȸ�� ��� ������
            stack.pop_back(); //���ÿ��� ����
            int tmp_num = top.first;  // ������ �� ��Ϲ����� �ε���
            int tmp_dir = top.second; // ���� ����
            if (tmp_dir == 1)
            { // �ð�������� ������
                li[tmp_num] = li[tmp_num].back() + li[tmp_num].substr(0, 7);
            }
            else
            { // �ݽð�������� ������
                li[tmp_num] = li[tmp_num].substr(1) + li[tmp_num][0];
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < t; ++i)
    {
        if (li[i][0] == '1') //12�ù��� ��ϰ� 1�̸� ī��Ʈ ����
        {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}