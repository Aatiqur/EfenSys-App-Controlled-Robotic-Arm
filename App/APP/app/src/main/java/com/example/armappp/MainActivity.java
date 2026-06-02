package com.example.armappp;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.TextView;

import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

import java.util.HashMap;
import java.util.Map;

public class MainActivity extends AppCompatActivity
{
    DatabaseReference databaseRef = FirebaseDatabase.getInstance().getReference();
    SeekBar seekbar1,seekbar2,seekbar3,seekbar4,seekbar5;
    int seekVal1,seekVal2,seekVal3,seekVal4,seekVal5;
    Button btn_save,btn_run_pause,btn_reset;
    DataSend dataSend;
    String value;
    int run_pause = 0;

    @SuppressLint("WrongViewCast")
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        seekbar1 = findViewById(R.id.seekBar1);
        seekbar2 = findViewById(R.id.seekBar2);
        seekbar3 = findViewById(R.id.seekBar3);
        seekbar4 = findViewById(R.id.seekBar4);
        seekbar5 = findViewById(R.id.seekBar5);
        btn_save = findViewById(R.id.btn_save);
        btn_run_pause = findViewById(R.id.btn_run_pause);
        btn_reset = findViewById(R.id.btn_reset);


        seekBarData();
        buttonData();


    }

    public void seekBarData()
    {
        seekbar1.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener()
        {
            @Override
            public void onProgressChanged(SeekBar seekBar, int val1, boolean b)
            {
                seekVal1 = val1;
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar)
            {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar)
            {
                value = "s1"+String.valueOf(seekVal1);
                dataSend = new DataSend(value);
                databaseRef.child("ARM").setValue(dataSend);
            }
        });

        seekbar2.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener()
        {
            @Override
            public void onProgressChanged(SeekBar seekBar, int val2, boolean b)
            {
                seekVal2 = val2;
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar)
            {}

            @Override
            public void onStopTrackingTouch(SeekBar seekBar)
            {
                value = "s2"+String.valueOf(seekVal2);
                dataSend = new DataSend(value);
                databaseRef.child("ARM").setValue(dataSend);
            }
        });

        seekbar3.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener()
        {
            @Override
            public void onProgressChanged(SeekBar seekBar, int val3, boolean b)
            {
                seekVal3 = val3;
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar)
            {}

            @Override
            public void onStopTrackingTouch(SeekBar seekBar)
            {
                value = "s3"+String.valueOf(seekVal3);
                dataSend = new DataSend(value);
                databaseRef.child("ARM").setValue(dataSend);
            }
        });

        seekbar4.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener()
        {
            @Override
            public void onProgressChanged(SeekBar seekBar, int val4, boolean b)
            {
                seekVal4 = val4;
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar)
            {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar)
            {
                value = "s4"+String.valueOf(seekVal4);
                dataSend = new DataSend(value);
                databaseRef.child("ARM").setValue(dataSend);
            }
        });

        seekbar5.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener()
        {
            @Override
            public void onProgressChanged(SeekBar seekBar, int val5, boolean b)
            {
                seekVal5 = val5;
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar)
            {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar)
            {
                value = "s5"+String.valueOf(seekVal5);
                dataSend = new DataSend(value);
                databaseRef.child("ARM").setValue(dataSend);
            }
        });
    }

    public void buttonData()
    {
        btn_save.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                dataSend = new DataSend("SAVE");
                databaseRef.child("ARM").setValue(dataSend);
            }
        });

        btn_run_pause.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                if(run_pause == 0)
                {
                    btn_run_pause.setText("Run");
                    dataSend = new DataSend("PAUSE");
                    databaseRef.child("ARM").setValue(dataSend);
                    run_pause = 1;

                }
                else
                {
                    btn_run_pause.setText("Pause");
                    dataSend = new DataSend("RUN");
                    databaseRef.child("ARM").setValue(dataSend);
                    run_pause = 0;
                }
            }
        });

        btn_reset.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                dataSend = new DataSend("RESET");
                databaseRef.child("ARM").setValue(dataSend);
            }
        });
    }
}