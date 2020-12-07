#include <stdio.h>
#include <stdlib.h>


struct stNode
{
	unsigned int ulData;
	struct stNode *pNext;
	struct stNode *pPrev;
	
};

typedef enum
{
	ERR_NONE,
	ERR_MEM_ALLOC_FAILED,	
	ERR_MAX
	
} eErrorList;

static struct stNode *pHead = NULL;
static struct stNode *pTail = NULL;


eErrorList PushFront( unsigned int ulData )
{
	eErrorList eErrStatus = ERR_NONE;
	
	struct stNode *pNewNode = ( struct stNode * ) calloc( 1, sizeof( struct stNode ) );
	
	if( NULL != pNewNode )
	{
		pNewNode->ulData = ulData;
		pNewNode->pPrev = NULL;
		pNewNode->pNext = NULL;
		
		if( NULL == pHead )
		{
			pHead = pNewNode;
			pTail = pNewNode;
		}
		else
		{
			pHead->pPrev = pNewNode;
			pNewNode->pNext = pHead;
			pHead = pNewNode;
		}	
	}
	else
	{
		eErrStatus = ERR_MEM_ALLOC_FAILED;
	}
	
	return eErrStatus;
}



eErrorList PushBack( unsigned int ulData )
{
	eErrorList eErrStatus = ERR_NONE;
	
	struct stNode *pNewNode = ( struct stNode * ) calloc( 1, sizeof( struct stNode ) );
	
	if( NULL != pNewNode )
	{
		pNewNode->ulData = ulData;
		
		if( NULL == pTail )
		{
			pTail = pNewNode;
			pHead = pNewNode;
		}
		else
		{
			pTail->pNext = pNewNode;
			pNewNode->pPrev = pTail;
			pTail = pNewNode;
		}	
	}
	else
	{
		eErrStatus = ERR_MEM_ALLOC_FAILED;
	}
	
	return eErrStatus;	
}


struct stNode *GetNext( struct stNode *pCurrentNode )
{
	struct stNode *pTmpHead = pHead;
	
	while( NULL != pTmpHead )
	{
		if( pCurrentNode == pTmpHead )
		{
			break;
		}
		
		pTmpHead = pTmpHead->pNext;
	}
	
	return pTmpHead->pNext;
}


struct stNode *GetPrev( struct stNode *pCurrentNode )
{
	struct stNode *pTmpTail = pTail;
	
	while( NULL != pTmpTail )
	{
		if( pCurrentNode == pTmpTail )
		{
			break;
		}
		
		pTmpTail = pTmpTail->pPrev;
	}
	
	return pTmpTail->pPrev;
}

struct stNode *DeleteNode( unsigned int ulData )
{
	struct stNode *pCurrentNode = pHead;
	unsigned char ubFlag = 0U; 
	
		while( NULL != pCurrentNode )
		{
			if( ulData == pCurrentNode->ulData )
			{
				/* Single node within a list */
				if( ( NULL == pCurrentNode->pPrev ) && ( NULL == pCurrentNode->pNext ) )
				{
					/* Do nothing...*/
				}
				/* Multiple nodes present (Location : At the head) */
				else if( ( NULL == pCurrentNode->pPrev ) && ( NULL != pCurrentNode->pNext ) )
				{
					pHead = pCurrentNode->pNext;
					pHead->pPrev = NULL;
				}
				/* Multiple nodes present (Location : At the Tail) */
				else if( ( NULL != pCurrentNode->pPrev ) && ( NULL == pCurrentNode->pNext ) )
				{
					pTail = pCurrentNode->pPrev;
					pTail->pNext = NULL;
				}
				/* Multiple nodes present (Location : At the middle) */
				else
				{
					/* Link previous node to next node */
					pCurrentNode->pPrev->pNext = pCurrentNode->pNext;
					pCurrentNode->pNext->pPrev = pCurrentNode->pPrev;
				}
				
				ubFlag = 1U;
				break;
			}

			pCurrentNode = pCurrentNode->pNext;
		}

	if( 0U == ubFlag )
		pCurrentNode = NULL;

	return pCurrentNode;
}


void PrintList( void )
{
	struct stNode *pCurrentNode = pHead;

	while( NULL != pCurrentNode )
	{
		printf( "##%d\t%d\n", pCurrentNode, pCurrentNode->ulData );
		
		pCurrentNode = pCurrentNode->pNext;
	}
}

void ReverseList( void )
{
	struct stNode *pCurrentNode = pHead;
	struct stNode *pTmpPrev = NULL;
	
	while( NULL != pCurrentNode )
	{
		pTmpPrev = pCurrentNode->pPrev;
		pCurrentNode->pPrev = pCurrentNode->pNext;
		pCurrentNode->pNext = pTmpPrev;
		
		pCurrentNode = pCurrentNode->pPrev;
	}
	
	/* check the boundary condition before moving the Head */
	if( NULL != pTmpPrev )
	pHead = pTmpPrev->pPrev;
}

int main( void )
{
	unsigned int a = 1, b = 2, c = 3, d = 4, e = 5;
	PushFront( a );
	PushFront( b );
	PushFront( c );
	PushFront( d );
	PushBack( c );
	PushBack( d );
	PushBack( e );
	
	PrintList();
	
	ReverseList();
	printf( "$$$$$$\n");
	struct stNode *DeletedNode = DeleteNode(1);
	printf( "\n Deleted Node %d\n", DeletedNode->ulData );
	
	PrintList();
	
	
	return 0;
}