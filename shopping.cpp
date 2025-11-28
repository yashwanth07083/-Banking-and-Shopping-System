class shopping
{
    shop a[20];
    static int totalitems;
    float totalamount=0;
    public:void shoppingmenu()
           {
              cout<<"----Welcome to Shopping----"<<endl;
              cout<<"1.Add to cart 2.View cart 3.Delete item 4.Billing 5.break"<<endl;
           }
           void addtocart()
           {
               if(totalitems<20)
               {
                 cout<<"Enter the item to add"<<endl;
                 cin.ignore();
                 getline(cin,a[totalitems].name);
                 cout<<"Enter the Price of product:"<<endl;
                 cin>>a[totalitems].price;
                 cout<<"Enter the Number of quantities you want:"<<endl;
                 cin>>a[totalitems].quantity;
                 cout<<endl;
                 cout<<"Adding item:"<<a[totalitems].name<<"  Price:"<<a[totalitems].price<<"  Quantity:"<<a[totalitems].quantity<<endl;
                 cout<<"Item Added Successfully"<<endl;
                 totalamount+=((a[totalitems].price)*(a[totalitems].quantity));
                 totalitems++;
               }
               else
                cout<<"Cart is full"<<endl;
           }
           void viewcart()
           {
               if(totalitems==0)
               {
                   cout<<"Cart is empty"<<endl;
               }
               else
               {
                   cout<<"Cart Details:"<<endl;
                   cout<<"num|Item|Price|Quantity|Total"<<endl;
                   for(int i=0;i<totalitems;i++)
                   {

                     cout<<i+1<<" "<<a[i].name<<" "<<a[i].price<<" "<<a[i].quantity<<" "<<"Total:"<<((a[i].price)*(a[i].quantity))<<endl;
                   }
                   cout<<"Total Amount is:"<<totalamount<<endl;
               }
           }
           void deleteitem()
           {
               if(totalitems==0)
               {
                   cout<<"Cart is empty"<<endl;
               }
               else
               {
                   int flag=0,ch;
                   string n;
                   cout<<"Enter choice 1.delete item 2.Edit item quantity"<<endl;
                   cin>>ch;
                   switch(ch)
                   {
                        case 1:cout<<"Enter item to delete"<<endl;
                               cin>>n;
                               for(int i=0;i<totalitems;i++)
                               {
                                     if(n==a[i].name)
                                     {
                                         totalamount-=((a[i].price)*(a[i].quantity));
                                         flag=1;
                                          for(int j=i;j<totalitems;j++)
                                          {
                                              a[j]=a[j+1];
                                          }
                                          totalitems--;
                                     }
                                     if(flag==1)
                                     {
                                         cout<<"Item Deleted successfully"<<endl;
                                         cout<<"Total Amount is:"<<totalamount<<endl;
                                         break;
                                     }
                               }
                               if(!flag)
                               {
                                   cout<<"Item not found"<<endl;
                               }
                               break;
                        case 2:cout<<"Enter item to Edit quantity"<<endl;
                               cin>>n;
                               for(int i=0;i<totalitems;i++)
                               {
                                   if(n==a[i].name)
                                   {
                                       int k;
                                       totalamount-=((a[i].price)*(a[i].quantity));
                                       flag=1;
                                       cout<<"Item quantities are:"<<a[i].quantity<<endl;
                                       cout<<"Enter how much quantities u want:"<<endl;
                                       cin>>k;
                                       a[i].quantity=k;
                                       totalamount+=((a[i].price)*(a[i].quantity));
                                       cout<<"Quantities Edited successfully"<<endl;
                                       cout<<"Total amount:"<<totalamount<<endl;
                                       break;
                                   }
                               }
                               if(!flag)
                               {
                                   cout<<"Item not found to Edit quantity"<<endl;
                               }
                               break;
                        default:cout<<"Invalid choice"<<endl;
                       }
                   }
               }
               void setcartempty()
               {
                        totalitems=0;
                        totalamount=0;
                        cout<<"Cart is empty now"<<endl;
               }
                float gettotalAmount()
                {
                    return totalamount;
                }
              friend class bank;
};
int shopping::totalitems=0;