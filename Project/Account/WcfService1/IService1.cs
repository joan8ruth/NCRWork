using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

namespace WcfService1
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the interface name "IService1" in both code and config file together.
    [ServiceContract]
    public interface IService1
    {

        [OperationContract]
        string GetData(int value);

        [OperationContract]
        CompositeType GetDataUsingDataContract(CompositeType composite);

        [OperationContract]
        DataSet GetCustomerId(int customerEnteredId);

        [OperationContract]
        bool AddAccount(string[] d);

        [OperationContract]
        bool EditAccount(Account a);


        // TODO: Add your service operations here
    }


    // Use a data contract as illustrated in the sample below to add composite types to service operations.
    [DataContract]
    public class CompositeType
    {
        bool boolValue = true;
        string stringValue = "Hello ";

        [DataMember]
        public bool BoolValue
        {
            get { return boolValue; }
            set { boolValue = value; }
        }

        [DataMember]
        public string StringValue
        {
            get { return stringValue; }
            set { stringValue = value; }
        }
    }

    [DataContract]
    public class Customer
    {
        [DataMember]
        public long accountNo { get; set; }

        [DataMember]
        public  int customerId { get; set; }

        [DataMember]
        public string accountType { get; set; }

        [DataMember]
        public string DateOfOpen { get; set; }

        [DataMember]
        public string status { get; set; }

        [DataMember]
        public string dateOfEdited { get; set; }

        [DataMember]
        public string ClosingDate { get; set; }

        [DataMember]
        public string amount { get; set; }
        
    }

    [DataContract]
    public class Account
    {
        [DataMember]
        public long accountNo { get; set; }

        [DataMember]
        public int customerId{ get; set; }

        [DataMember]
        public string accountType{ get; set; }

        [DataMember]
        public string DateOfOpen{ get; set; }

        [DataMember]
        public string status{ get; set; }

        [DataMember]
        public string dateOfEdited{ get; set; }

        [DataMember]
        public string ClosingDate{ get; set; }

        [DataMember]
        public int amount{ get; set; }

    }
}
