#include "../includes/lem_in.h"


// QUEUE ARRAY
//t_queue		*create_queue()
//{
//	t_queue	*new_queue;
//	int		i;
//
//	i = 0;
//	new_queue = ft_memalloc(sizeof(t_queue));
//	new_queue->a = (t_room **)ft_memalloc(sizeof(t_room *) * QUEUE_SIZE);
//	while (i < QUEUE_SIZE)
//		new_queue->a[i++] = (t_room *)ft_memalloc(sizeof(t_room));
//	new_queue->back = -1;
//	new_queue->front = -1;
//	return (new_queue);
//}
//
//void		enqueue(t_queue *queue, t_room *room)
//{
//	if (queue->front == -1)
//		queue->front++;
//	if (queue->back  == QUEUE_SIZE - 1)
//		exit(1);
//	else
//		queue->a[++queue->back] = room;
//}
//
//t_room		*dequeue(t_queue *queue)
//{
//	t_room *tmp;
//
//	tmp = queue->a[queue->front];
//	queue->a[queue->front] = NULL;
//	return (tmp);
//}
//
//void		display(t_queue *queue)
//{
//	int i;
//
//	i = 0;
//	while (i <= queue->back)
//	{
//		if (queue->a[i] != NULL)
//		{
//			ft_printf("NODE = %s, X = %d, Y = %d, BFS lvl = %d, IN degree = %d, OUT degree %d\n",
//					queue->a[i]->name, queue->a[i]->coord_x,
//					queue->a[i]->coord_y, queue->a[i]->bfs_lvl,
//					queue->a[i]->in_degree, queue->a[i]->out_degree);
//		}
//		i++;
//	}
//}

//QUEUE LINKED LIST

void print_queue(t_queue *queue)
{
	t_qnode *tmp;

	tmp = queue->front;
	ft_putstr(RED);
	ft_printf("Current queue");

	while (tmp)
	{
		if (tmp->room && tmp->room->name)
			ft_printf(" %s", tmp->room->name);
		tmp = tmp->next;
	}
	ft_putstr(RESET);
	ft_putchar('\n');
}

t_qnode		*queue_get_front(t_queue **queue)
{
	t_qnode		*node;

	node = NULL;
	if (queue && *queue)
	{
		if ((*queue)->front->next == NULL)
		{
			node = (*queue)->front;
			(*queue)->front = NULL;
			(*queue)->rear = NULL;
		}
		else
		{
			node = (*queue)->front;
			(*queue)->front = (*queue)->front->next;
		}
	}
	return (node);
}

t_qnode		*queue_new_node(t_room *room)
{
	t_qnode *new_node;

	if (!(new_node = ft_memalloc(sizeof(t_qnode))))
		return (NULL);
	new_node->room = room;
	new_node->next = NULL;
	return (new_node);
}

t_queue		*queue_create()
{
	t_queue *new_queue;

	if (!(new_queue = ft_memalloc(sizeof(t_queue))))
		return (NULL);
	new_queue->front = NULL;
	new_queue->rear = NULL;
	return (new_queue);
}

void		enqueue(t_queue *queue, t_room *room)
{
	t_qnode *tmp;

	if (!(tmp = queue_new_node(room)))
		return ;
	if (!queue->rear && !queue->front)
	{
		queue->rear = tmp;
		queue->front = tmp;
		return ;
	}
	queue->rear->next = tmp;
	queue->rear = tmp;
}

t_qnode		*dequeue(t_queue *queue)
{
	t_qnode *tmp;

	if (queue->front && queue->front->next)
	{
		tmp = queue->front;
		queue->front = queue->front->next;
		return (tmp);
	}
	if (queue->front && !queue->front->next)
	{
		tmp = queue->front;
		queue->front = NULL;
		queue->rear = NULL;
		return (tmp);
	}
	return (NULL);
}
