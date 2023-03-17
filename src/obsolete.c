t_list push_back_list(t_list lst, int data)
{
	t_list *element;
	element = malloc(sizeof(*element));
	if(element == NULL)
	{
		printf("malloc error");
		exit(EXIT_FAILURE);
	}	
	element->data = data;
	element->next = NULL;
	if(is_empty_list(lst))
		return element;
	t_list *temp;
	temp = lst;
	
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = element;
	return (lst);
}

//---------------------------------------------------------------

t_list *push_front_list(t_list *lst, int data)
{
	t_list *element;
	element = create_element(data);
	element->data = data;
	if(is_empty_list(&lst))
		element->next = NULL;
	else
		element->next= lst;
	return (lst);
}	

//-----------------------------------------------------------------

t_list pop_back_list(t_list lst)
{
	if(is_empty_list(lst))
		return new_list();
	if(lst->next == NULL)
	{
		free(lst);
		lst = NULL;
		return new_list();
	}
	t_list *temp = lst;
	t_list *before = lst;
	while(temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}
	before->next = NULL;
	free(temp);
	temp = NULL;
	return lst;
}
//---------------------------------------------------------
t_list	pop_front_list(t_list lst)
{
	if (is_empty_list(lst))
		return(lst);
	
	t_list *element;
	element = malloc(sizeof(*element));
	if (element == NULL)
	{
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
	element = lst->element;
	free(lst);
	lst = NULL;
		
	return (element);
}

//-----------------------------------------
