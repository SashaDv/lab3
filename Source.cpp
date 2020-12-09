#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

void f1();
void f2();
void f3();

int n1 = 0, n2 = 0, n3 = 0;

int main() {
	char c;
	HANDLE thread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)f1, NULL, 0, NULL);
	if (thread1 == NULL) return GetLastError();
	HANDLE thread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)f2, NULL, 0, NULL);
	if (thread2 == NULL) return GetLastError();
	HANDLE thread3 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)f3, NULL, 0, NULL);
	if (thread3 == NULL) return GetLastError();
	do
	{
		cout << "Click 'v' to display a thread with the biggest number, 'q' to exit" << endl;
		cin >> c;
		if (c == 'v') {
			if (n1 >= n2 && n1 >= n3) cout << "Thread 1 - " << n1 << endl;
			else if (n2 >= n1 && n2 >= n3) cout << "Thread 2 - " << n2 << endl;
			else cout << "Thread 3 - " << n3 << endl;
		}
	} while (c != 'q');
	TerminateThread(thread1, 0);
	CloseHandle(thread1);
	TerminateThread(thread2, 0);
	CloseHandle(thread2);
	TerminateThread(thread3, 0);
	CloseHandle(thread3);
	return 0;
}

void f1() {
	cout << "Thread 1 started" << endl;
	while (true)
	{
		n1++;
		Sleep(300);
	}
	return;
}

void f2() {
	Sleep(1200);
	cout << "Thread 2 started" << endl;
	while (true)
	{
		n2++;
		Sleep(100);
	}
	return;
}

void f3() {
	Sleep(300);
	cout << "Thread 3 started" << endl;
	while (true)
	{
		n3++;
		Sleep(200);
	}
	return;
}