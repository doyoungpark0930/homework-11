/*
 * graph-search.c
 * 작성자 :박도영
 * 작성일자: 2021/05/20
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct node {
	int vertex;
	struct node* link;
} Node;
#define FALSE 0
#define TRUE 1
int visited[10]={0,};//DFS에서 방문 됐는지 확인하기 위한 배열 선언
Node graph[10]; //그래프 해드 노드들을 전역변수로 선언
void InitializeGraph();  //그래프 초기화
void freeGraph();//그래프 할당해제
void freeNode(Node* ptr);//그래프 해드노드들에 연결된 리스트들 모두 할당해제
void InsertVertex(int vertex); //Vertex 입력
int InsertEdge(int FirstVertex, int SecondVertex); //두 vertex사이에 edge입력
void DepthFirstSearch(int v);	//그래프의 정점v에서 시작하는 깊이 우선 탐색
void initializeDFS();
void BreathFirstSearch(int v);
void printGraph();


int main()
{
	printf("Do young park/2018038077\n");
	for (int i = 0; i < 10; i++) //초기 그래프 초기화
	{
		graph[i].vertex = -9999;
		graph[i].link = NULL;
	}
	char command;
	int vertex;
	int v;
	int FirstVertex, SecondVertex;
	do {
		printf("\n\n");


		printf("----------------------------------------------------------------\n");
		printf("                       Graph search                             \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Graph       = z                                     \n");
		printf(" Insert Vertex          = v      Insert Edge                = e \n");
		printf(" Depth First Search     = d      Breath First Search        = b \n");
		printf(" Print Graph            = p      Quit                       = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'z': case 'Z':
			InitializeGraph();
			break;
		case 'q': case 'Q':
			freeGraph();
			break;
		case 'v': case 'V':
			printf("Your Vertex = ");
			scanf("%d", &vertex);
			InsertVertex(vertex);
			break;
		case 'e': case 'E':
			printf("FirstVertex = ");
			scanf("%d", &FirstVertex);
			printf("SecondVertex = ");
			scanf("%d", &SecondVertex);
			InsertEdge(FirstVertex, SecondVertex);
			break;
		case 'd': case 'D':
			printf("Vertex to start = ");
			scanf("%d",&v);
			DepthFirstSearch(v);
			initializeDFS();
			break;
		case 'b': case 'B':
			//BreathFirstSearch();
			break;
		case 'p': case 'P':
			printGraph();
			break;

		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}

void InitializeGraph()    //그래프 초기화
{
	freeGraph();

}

void freeGraph()
{
	for (int i = 0; i < 10; i++)	//그래프 해드들의 vertex에 쓰레기 값을 넣는다, link들이 NULL을 가리키게 한다
	{
		if (graph[i].link != NULL)
		{
			freeNode(graph[i].link);
			graph[i].vertex = -9999;
			graph[i].link = NULL;
		}
	}
}

void freeNode(Node* ptr)
{
	if (ptr->link)
	{
		freeNode(ptr->link);
	}
	free(ptr);
}


void InsertVertex(int vertex)    //vertex를 하나 추가한다
{
	if (vertex >= 0 && vertex < 10)	//vertex가 0이상 9이하라면 graph의 vertex에 추가
		graph[vertex].vertex = vertex;
	else
		printf("you can input only number from 0 to 9\n");

}

void printGraph()
{
	Node* ptr;
	for (int i = 0; i < 10; i++)
	{
		if (graph[i].vertex >= 0)	//헤드노드의 vertex에 값이 입력이 되어있다면
		{
			ptr = graph[i].link;
			printf("headNode[%d] = %d  ", i, graph[i].vertex);
			while (ptr)
			{
				printf("listNode = %d  ", ptr->vertex);
				ptr = ptr->link;
			}
			printf("\n");

		}
	}
}

int InsertEdge(int FirstVertex, int SecondVertex)
{
	if (graph[FirstVertex].vertex == FirstVertex && graph[SecondVertex].vertex == SecondVertex) //두 vertex들이 모두 존재한다면
	{
		Node* ptr;
		ptr = &graph[FirstVertex];
		while (ptr->link) //graph[FirstVertex]의 마지막 링크를 가리키도록
		{
			ptr = ptr->link;
			if (ptr->vertex == SecondVertex) //두 vertex사이에 edge가 존재한다면 빠져나온다
			{
				printf("Edge is already between FirstEdge and SecondEdge\n");
				return 0;
			}
		}
		ptr->link = (Node*)malloc(sizeof(Node));
		ptr->link->vertex = SecondVertex;
		ptr->link->link = NULL;

		ptr = &graph[SecondVertex];
		while (ptr->link) //graph[SecondVertex]의 마지막 링크를 가리키도록
		{
			ptr = ptr->link;
		}
		ptr->link = (Node*)malloc(sizeof(Node));
		ptr->link->vertex = FirstVertex;
		ptr->link->link = NULL;
	}
	else
	{
		printf("cannot add edge\n");
	}
}

void DepthFirstSearch(int v)
{
	Node *ptr;
	visited[v]= TRUE;
	printf("%5d",v);
	for(ptr=&graph[v];ptr!=NULL;ptr=ptr->link)
	{
		if(!visited[ptr->vertex])
			DepthFirstSearch(ptr->vertex);
	}
}
void initializeDFS()
{
	for(int i=0;i<10;i++)
	{
		visited[i]=FALSE;
	}
}