using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Linq;
using System.ServiceProcess;
using System.Text;

using System.Threading.Tasks;
using System.Timers;

namespace WindowsService1
{
    public partial class Service1 : ServiceBase
    {
        private int eventId = 0;
       
        public Service1()
        {
            //int eventId = 0;
            InitializeComponent();
            eventLog1 = new EventLog();

            if(!EventLog.SourceExists("CDACServices"))
            {
                EventLog.CreateEventSource("CDACServices", "NewLog");
            }

            eventLog1.Source = "CDACServices";
            eventLog1.Log = "NewLog";
        }

        protected override void OnStart(string[] args)
        {
            
            eventLog1.WriteEntry("In OnStart");

            Timer timer = new Timer();
            timer.Interval = 20000;
            timer.Elapsed += new ElapsedEventHandler(this.OnTimer);
            timer.Start();


        }

        public void OnTimer(object sender,ElapsedEventArgs args )
        {
            eventLog1.WriteEntry("Monitring the system", EventLogEntryType.Information,eventId++);
        }

        protected override void OnStop()
        {
        }

        private void eventLog1_EntryWritten(object sender, EntryWrittenEventArgs e)
        {

        }
    }
}
