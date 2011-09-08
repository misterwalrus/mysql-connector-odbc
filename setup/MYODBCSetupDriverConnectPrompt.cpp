/* Copyright (c) 2004, 2010, Oracle and/or its affiliates. All rights reserved.

   The MySQL Connector/ODBC is licensed under the terms of the GPLv2
   <http://www.gnu.org/licenses/old-licenses/gpl-2.0.html>, like most
   MySQL Connectors. There are special exceptions to the terms and
   conditions of the GPLv2 as it is applied to this software, see the
   FLOSS License Exception
   <http://www.mysql.com/about/legal/licensing/foss-exception.html>.
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published
   by the Free Software Foundation; version 2 of the License.
   
   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
   for more details.
   
   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */

#include "MYODBCSetupDataSourceDialog.h"

/*!
    OSX

    We get an alarming warning from qt when we fail to provide
    the app name with a fully qualified absolute path. And the
    problem is that we do not have any real app path to give -
    so we make one up. Perhaps the real app name can be found
    but this seems to work. (busy busy so moveon.org)
*/
static char *pszAppName = "/usr/bin/myodbc3c";

BOOL MYODBCSetupDriverConnectPrompt( SQLHDBC hDBC, HWND hWnd, MYODBCUTIL_DATASOURCE *pDataSource )
{
    BOOL bReturn = FALSE;

    /*!
        MYODBC RULE

        No window handle - no gui - regardless of the fact that we may not 
        use the window handle anyway :) 

        We will provide a GUI for any non-zero value but on XP the DM tries to be 
        too smart for us - and complains about an invalid window handle. This 
        prevents this trick from working on XP which in turn prevents console
        applications from invoking GUI (unless they can come up with a viable
        window handle).
    */    
    if ( !hWnd )
        return FALSE;

    if ( !qApp )
    {
// METHOD 1
//        int     argc    = 1;
//        char *  argv[]  = { pszAppName, NULL };
//        static QApplication app( argc, argv );
//
//        MYODBCSetupDataSourceDialog dialogDataSource( NULL, hDBC, pDataSource );
//
//        app.connect( &app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()) ); 
//        dialogDataSource.show(); 
//        if ( app.exec() == QDialog::Accepted )
//            bReturn = TRUE; 

// METHOD 2 (tested to work on XP)
        int     argc    = 1;
        char *  argv[]  = { pszAppName, NULL };
        QApplication app( argc, argv );

        // We are most likely to come in this route as caller is unlikely to have a qApp */ 
        MYODBCSetupDataSourceDialog dialogDataSource( NULL, hDBC, pDataSource );

        if ( dialogDataSource.exec() == QDialog::Accepted )
            bReturn = TRUE; 
    }
    else
    {
// METHOD 1
//        MYODBCSetupDataSourceDialog *pdialogDataSource = new MYODBCSetupDataSourceDialog( NULL, hDBC, pDataSource );
//        if ( pdialogDataSource->exec() == QDialog::Accepted )
//            bReturn = TRUE; 
// 

// METHOD 2 (tested to work on XP)
        MYODBCSetupDataSourceDialog dialogDataSource( NULL, hDBC, pDataSource );

        if ( dialogDataSource.exec() == QDialog::Accepted )
            bReturn = TRUE; 
    }

    return bReturn;
}


