#include <iostream>
#include <queue>
#include <vector>

using namespace std;


struct info {
    int idx;        // ó�� �ٿ� �� ��ȣ
    int line_num;   // m���� �� �� ���� ���� ��ȣ
    int work_days;  // �ٹ� �ϼ�
    int urgency;    // ���� ����
};

struct cmp { //�켱����ť ���� ����
    bool operator()(const info& child, const info& parent) {
        if (parent.work_days != child.work_days) { 
            return parent.work_days > child.work_days; //�� ���� ���� �������
        }
        if (parent.urgency != child.urgency) {
            return parent.urgency > child.urgency; //�� ���� �������
        }
        return parent.line_num < child.line_num; //�� ���ٿ� �ִ� ������� 
    }
};

int simulation(int m, int k, vector<queue<info>>& lines) {
    // �� ���� ���ε��� ����Ǵ� �켱���� ť
    priority_queue<info, vector<info>, cmp> pq; //���θ� ���� �켱���� ť

    // �켱���� ť �ʱ�ȭ
    for (int i = 0; i < m; i++) {
        if (!lines[i].empty()) { //���� ������� �ʴٸ�
            pq.push(lines[i].front()); //���θ� �켱���� ť�� �߰�
            lines[i].pop();
        }
    }

    // k ���ʰ� ���� �� ȭ����� ����� ����� ��
    int count = 0;

    while (!pq.empty() && pq.top().idx != k) {  // k�� ���ʰ� �Ǳ� ������
        int line_num = pq.top().line_num; //�켱���� ���� ���� ����� �� ��ȣ
        pq.pop();  //�켱���� ���� ���� ��� ȭ��� �̿�

        if (!lines[line_num].empty()) { 
            pq.push(lines[line_num].front()); //����� �� �� ���θ� �켱����ť�� �߰�
            lines[line_num].pop(); //ť������ ����
        }
        
        count++;
    }

    return count;
}

/**
 * [ȭ����� ��Ģ] - �켱���� ť & �ùķ��̼� ����
 *
 * 1. �� ����� (�� ���� % m) ��° ���� �ڿ� ���� �ȴ�.
 * 2. �� ����, ��� ���� �� ��� �߿� �켱 ������ ���� ���� ������� ȭ����� �̿��Ѵ�.
 *
 * <�켱����>
 * 1. �ٹ� ���ڰ� ���� ���
 * 2. �� ���� ���
 * 3. �� ��ȣ�� �ռ� ���
 *
 * ---
 * 1. �� ���� ���� �� ����� ���� ������ ������, ť�� �̿��� �����Ѵ�.
 * 2. ��� ���� ���θ� �켱���� ť�� �ְ�, �켱������ ���� �ռ� ������� �����Ѵ�.
 * 3. � ���� ���ΰ� ȭ����� �̿�������, �� ���� ���θ� �켱 ���� ť�� �ִ´�.
 *
 * �̶�, 0������ ǥ���ϹǷ� ��ī�� idx�� k�� �ȴ�.
 *
 * !����! ť���� ����� ���� �켱 ���� ť�� ���� ��, �׻� ť�� ������� ������ Ȯ��
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, d, h;
    cin >> n >> m >> k;

    vector<queue<info>> lines(m, queue<info>()); //m���� �� ���� ť �����

    // �Է�
    for (int i = 0; i < n; i++) {
        cin >> d >> h;
        lines[i % m].push({ i, i % m, d, h }); //ť�� ���(�� �����)
    }

    // ���� & ���
    cout << simulation(m, k, lines);

    return 0;
}