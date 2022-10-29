
import javax.swing.JOptionPane;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Qureshi Home
 */
public class AttenuationCalculator extends javax.swing.JFrame {

    /**
     * Creates new form AttenuationCalculator
     */
    public AttenuationCalculator() {
        initComponents();
        this.setDefaultCloseOperation(2);
        ManageTxtEditable();
    }


    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        l1 = new javax.swing.JLabel();
        txt1 = new javax.swing.JTextField();
        l2 = new javax.swing.JLabel();
        txt2 = new javax.swing.JTextField();
        CalcBtn = new javax.swing.JButton();
        Title = new javax.swing.JLabel();
        txt3 = new javax.swing.JTextField();
        l3 = new javax.swing.JLabel();
        jcb = new javax.swing.JComboBox<>();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jPanel1.setBackground(new java.awt.Color(0, 0, 0));

        l1.setFont(new java.awt.Font("Arial", 0, 11)); // NOI18N
        l1.setForeground(new java.awt.Color(255, 255, 255));
        l1.setText("Input - P1");

        txt1.setFont(new java.awt.Font("Arial", 0, 11)); // NOI18N

        l2.setFont(new java.awt.Font("Arial", 0, 11)); // NOI18N
        l2.setForeground(new java.awt.Color(255, 255, 255));
        l2.setText("Output - P2");

        txt2.setFont(new java.awt.Font("Arial", 0, 11)); // NOI18N

        CalcBtn.setBackground(new java.awt.Color(51, 51, 51));
        CalcBtn.setFont(new java.awt.Font("Arial", 0, 11)); // NOI18N
        CalcBtn.setForeground(new java.awt.Color(255, 153, 0));
        CalcBtn.setText("Calculate");
        CalcBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CalcBtnActionPerformed(evt);
            }
        });

        Title.setFont(new java.awt.Font("Yahoo", 0, 18)); // NOI18N
        Title.setForeground(new java.awt.Color(255, 153, 0));
        Title.setText("Attenuation CAlculator");

        txt3.setFont(new java.awt.Font("Arial", 0, 11)); // NOI18N

        l3.setFont(new java.awt.Font("Arial", 0, 11)); // NOI18N
        l3.setForeground(new java.awt.Color(255, 255, 255));
        l3.setText("Attenuation - dB");

        jcb.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Attenuation - dB", "Input - P1", "Output - P2" }));
        jcb.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                jcbItemStateChanged(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addContainerGap(22, Short.MAX_VALUE)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                        .addComponent(Title)
                        .addGap(32, 32, 32))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                        .addComponent(jcb, javax.swing.GroupLayout.PREFERRED_SIZE, 162, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(151, 151, 151))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addComponent(l3)
                                .addGap(18, 18, 18)
                                .addComponent(txt3, javax.swing.GroupLayout.PREFERRED_SIZE, 131, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addComponent(CalcBtn, javax.swing.GroupLayout.PREFERRED_SIZE, 209, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(126, 126, 126))))
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(22, 22, 22)
                .addComponent(l1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(txt1, javax.swing.GroupLayout.PREFERRED_SIZE, 115, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(51, 51, 51)
                .addComponent(l2)
                .addGap(18, 18, 18)
                .addComponent(txt2, javax.swing.GroupLayout.PREFERRED_SIZE, 115, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(20, 20, 20)
                .addComponent(Title)
                .addGap(32, 32, 32)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(l1)
                    .addComponent(txt1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(l2)
                    .addComponent(txt2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 44, Short.MAX_VALUE)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(l3)
                    .addComponent(txt3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(30, 30, 30)
                .addComponent(jcb, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(CalcBtn)
                .addGap(42, 42, 42))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void CalcBtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_CalcBtnActionPerformed
        float dB=0,P1=0,P2=0;
        try{
            if(!"".equals(txt1.getText()))
            P1=Float.parseFloat(txt1.getText());
            else
            P1=0;
        }catch(NumberFormatException e){
            NumberError(l1.getText());

        }
        try{
            if(!"".equals(txt2.getText()))
            P2=Float.parseFloat(txt2.getText());
            else
            P2=0;
        }catch(NumberFormatException e){
            NumberError(l2.getText());
        }
        try{
            if(!"".equals(txt3.getText()))
            dB=Float.parseFloat(txt3.getText());
            else
            dB=0;
        }catch(NumberFormatException e){
            NumberError(l3.getText());
        }
        switch(jcb.getSelectedIndex()){
            case 0:{
                dB= (float) (10 * Math.log10(P2/P1));
                txt3.setText(dB+"");
                System.out.print(dB);
                break;
            }
            case 1:{
                P1= (float) (P2/Math.pow(10,(dB/10)));
                txt1.setText(P1+"");
                break;
            }
            case 2:{
                P2 = (float) (P1 * Math.pow(10,(dB/10)));
                txt2.setText(P2+"");
                break;
            }
        }
    }//GEN-LAST:event_CalcBtnActionPerformed

    private void jcbItemStateChanged(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_jcbItemStateChanged
        ManageTxtEditable();
    }//GEN-LAST:event_jcbItemStateChanged
     public void NumberError(String a){
         JOptionPane.showMessageDialog (null, a+" Should be in Number \n", "Invalid Information", JOptionPane.ERROR_MESSAGE);
    }
     private void ManageTxtEditable(){
        txt1.setEnabled(true);
        txt2.setEnabled(true);
        txt3.setEnabled(true);
        switch(jcb.getSelectedIndex()){
                case 0:{
                     txt3.setEnabled(false);
                     txt3.setText("");
                     break;
                }
                case 1:{
                     txt1.setEnabled(false);
                     txt1.setText("");
                     break;
                }
                case 2:{
                     txt2.setEnabled(false);
                     txt2.setText("");
                     break;
                }
                }
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(AttenuationCalculator.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(AttenuationCalculator.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(AttenuationCalculator.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(AttenuationCalculator.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new AttenuationCalculator().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton CalcBtn;
    private javax.swing.JLabel Title;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JComboBox<String> jcb;
    private javax.swing.JLabel l1;
    private javax.swing.JLabel l2;
    private javax.swing.JLabel l3;
    private javax.swing.JTextField txt1;
    private javax.swing.JTextField txt2;
    private javax.swing.JTextField txt3;
    // End of variables declaration//GEN-END:variables
}
