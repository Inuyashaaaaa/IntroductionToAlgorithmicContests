// List Reverse( List L )
// {
//     Position Old_head, New_head, Temp;
//     New_head = NULL;
//     Old_head = L->Next;

//     while ( Old_head )  {
//         Temp = Old_head->Next;
//         Old_head->Next = New_head;
//         New_head = Old_head;  
//         Old_head = Temp; 
//     }
//     L = New_head;
//     return L;
// }